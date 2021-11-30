/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:03:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/11/29 21:48:02 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_vars *vars)
{
	char	*cmd;
	char	**args;
	int	fd[2];
	int	pid;

	vars->path = get_env_path(vars->envp);
	vars->splited_path = ft_split(vars->path, ':');
	if (pipe(fd) == -1)
		exit(0);
	pid = fork();
	if (pid == CHILD)
	{
		vars->cmd1 = get_cmd(vars->argv[2]);
		cmd = get_cmd_path(vars->cmd1, 2, vars);
		args = ft_split(vars->argv[2], ' ');
		dup2(vars->infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(vars->infile);
		close(fd[1]);
		close(fd[0]);
		execve(cmd, args, vars->envp);
		//destroyer();
	}
	else
	{
		wait(NULL);
		vars->cmd2 = get_cmd(vars->argv[3]);
		cmd = get_cmd_path(vars->cmd2, 3, vars);
		args = ft_split(vars->argv[3], ' ');
		dup2(vars->outfile, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(vars->outfile);
		close(fd[0]);
		close(fd[1]);
		execve(cmd, args, vars->envp);
		//destroyer();
	}
}

	// char	*cmd;
	// char	*joined_cmd;
	// char	*joined_cmd_tmp;
	// char	**splited_argv;
	// int		i;

	// path = get_env_path(envp);
	// splited_path = ft_split(path, ':');
	// cmd = get_cmd(argv[1]);
	// joined_cmd_tmp = ft_strjoin("/", cmd);
	// i = 0;
	// while (splited_path[i])
	// {
	// 	joined_cmd = ft_strjoin(splited_path[i], joined_cmd_tmp);
	// 	if (access(joined_cmd, F_OK) == 0)
	// 	{
	// 		printf("OK\n");
	// 		splited_argv = ft_split(argv[1], ' ');
	// 		execve(joined_cmd, splited_argv, NULL);
	// 		free(joined_cmd_tmp);
	// 		free(joined_cmd);
	// 		free(cmd);
	// 		clear_double_pointer(splited_path);
	// 		clear_double_pointer(splited_argv);
	// 		exit(0);
	// 	}
	// 	free(joined_cmd);
	// 	i++;
	// }
	// clear_double_pointer(splited_path);
	// free(joined_cmd_tmp);
	// free(cmd);
	// printf("%d\n", argc);
	// return (0);
