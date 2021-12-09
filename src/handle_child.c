/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:46:36 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/08 21:24:42 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_child(t_vars *vars, int *pipe_fd)
{
	char	**cmd_list;
	char	*cmd_path;
	int		infile;

	close(pipe_fd[0]);
	infile = open(vars->argv[1], O_RDONLY);
	if (infile < 0)
	{
		print_error(NULL);
		ft_strclear2(vars->env_path);
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	cmd_list = get_cmd_list(vars->argv[2]);
	if (!cmd_list)
	{
		ft_strclear2(vars->env_path);
		exit(127);
	}
	cmd_path = get_cmd_path(cmd_list[0], vars->env_path);
	if (!cmd_path)
	{
		ft_strclear2(vars->env_path);
		ft_strclear2(cmd_list);
		exit(127);
	}
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	if (execve(cmd_path, cmd_list, vars->envp) == -1)
	{
		print_error(NULL);
		ft_strclear2(vars->env_path);
		ft_strclear2(cmd_list);
		free(cmd_path);
		exit(1);
	}
}
