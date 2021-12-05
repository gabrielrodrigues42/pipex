/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:24:28 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/05 12:00:49 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_exit(t_vars *vars)
{
	vars->path = NULL;
	close_files(vars);
	clear_cmds(vars);
	clear_cmds_path(vars);
	clear_double_pointer(vars->splited_path);
	clear_double_pointer(vars->cmd1_args);
	clear_double_pointer(vars->cmd2_args);
	exit(1);
}
