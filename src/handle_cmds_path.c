/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:23:36 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/07 17:28:42 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_cmds_path(t_vars *vars)
{
	vars->cmd1_path = get_cmd_path(vars->cmd1, vars->env_path);
	if (vars->cmd1_path == NULL)
	{
		clear_double_pointer(vars->env_path);
		clear_cmds(vars);
		close_files(vars);
		print_error("No such file or directory");
		exit(1);
	}
	vars->cmd2_path = get_cmd_path(vars->cmd2, vars->env_path);
	if (vars->cmd2_path == NULL)
	{
		free(vars->cmd1_path);
		clear_double_pointer(vars->env_path);
		clear_cmds(vars);
		close_files(vars);
		print_error("No such file or directory");
		exit(1);
	}
}
