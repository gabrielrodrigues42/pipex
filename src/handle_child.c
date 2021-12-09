/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:46:36 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/09 12:15:39 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_child(t_vars *vars, int *pipe_fd)
{
	char	**cmd_list;
	char	*cmd_path;
	int		infile;

	infile = open(vars->argv[1], O_RDONLY);
	if (infile < 0)
	{
		print_error(NULL);
		clear_exit(1, NULL, NULL, vars);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	cmd_list = get_cmd_list(vars->argv[2]);
	if (!cmd_list)
		clear_exit(127, NULL, NULL, vars);
	cmd_path = get_cmd_path(cmd_list[0], vars->env_path);
	if (!cmd_path)
		clear_exit(127, cmd_list, NULL, vars);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	if (execve(cmd_path, cmd_list, vars->envp) == -1)
	{
		print_error(NULL);
		clear_exit(1, cmd_list, cmd_path, vars);
	}
}
