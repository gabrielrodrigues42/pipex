/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:29:24 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/08 14:28:58 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_vars(t_vars *vars, int argc, char **argv, char **envp)
{
	vars->argc = argc;
	vars->argv = argv;
	vars->envp = envp;
	vars->env_path = NULL;
}
