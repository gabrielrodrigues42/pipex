/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmds_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:28:41 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/05 00:16:06 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_cmds_path(t_vars *vars)
{
	free(vars->cmd1_path);
	free(vars->cmd2_path);
	vars->cmd1_path = NULL;
	vars->cmd2_path = NULL;
}
