/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:46:59 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/09 12:21:10 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_exit(int status, char **cmd_list, char *cmd_path, t_vars *vars)
{
	if (vars->env_path)
		ft_strclear2(vars->env_path);
	if (cmd_list)
		ft_strclear2(cmd_list);
	if (cmd_path)
		free(cmd_path);
	exit(status);
}
