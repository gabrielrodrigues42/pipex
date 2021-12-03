/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:03:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/02 21:25:49 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(t_vars *vars)
{
	open_files(vars);
	vars->path = get_env_path(vars->envp);
	vars->splited_path = ft_split(vars->path, ':');
	handle_cmds(vars);
	handle_cmds_path(vars);
	vars->cmd1_args = ft_split(vars->argv[2], ' ');
	vars->cmd2_args = ft_split(vars->argv[3], ' ');
	clear_exit(vars);
	return (0);
}

	// pipe(fd);
	// pid = fork();
	// if (pid == -1)
	// {
	// 	perror("Error\n");
	// 	return (1);
	// }
	// if (pid == 0)
	// {
	// 	dup2(infile, STDIN_FILENO);
	// 	dup2(fd[1], STDOUT_FILENO);
	// 	close(infile);
	// 	close(fd[1]);
	// 	close(fd[0]);
	// 	if (execve(cmd_path1, cmd_args1, envp) == -1)
	// 		return (1);
	// }
	// else
	// {
	// 	wait(0);
	// 	dup2(outfile, STDOUT_FILENO);
	// 	dup2(fd[0], STDIN_FILENO);
	// 	close(outfile);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	if (execve(cmd_path2, cmd_args2, envp) == -1)
	// 		return (1);
	// }
