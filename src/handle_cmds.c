/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:10:51 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/06 23:26:44 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_cmds(t_vars *vars)
{
	vars->cmd1 = get_cmd(vars->argv[2]);
	if (vars->cmd1 == NULL)
	{
		clear_double_pointer(vars->env_path);
		close_files(vars);
		print_error("Command not found");
	}
	vars->cmd2 = get_cmd(vars->argv[3]);
	if (vars->cmd2 == NULL)
	{
		free(vars->cmd1);
		clear_double_pointer(vars->env_path);
		close_files(vars);
		print_error("Command not found");
	}
}
