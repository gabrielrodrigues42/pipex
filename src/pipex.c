/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:03:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/02 21:24:22 by gandrade         ###   ########.fr       */
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
