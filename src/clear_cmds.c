/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:45:09 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/05 00:16:01 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_cmds(t_vars *vars)
{
	free(vars->cmd1);
	free(vars->cmd2);
	vars->cmd1 = NULL;
	vars->cmd2 = NULL;;
}
