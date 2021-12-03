/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:45:09 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/02 20:28:04 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	clear_cmds(t_vars *vars)
{
	free(vars->cmd1);
	free(vars->cmd2);
	vars->cmd1 = NULL;
	vars->cmd2 = NULL;
	return (0);
}
