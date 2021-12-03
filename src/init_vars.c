/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:29:24 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/02 21:09:07 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_vars(t_vars *vars, int argc, char **argv, char **envp)
{
	vars->argc = argc;
	vars->argv = argv;
	vars->envp = envp;
	vars->infile = 0;
	vars->outfile = 0;
	vars->path = NULL;
	vars->splited_path = NULL;
	vars->cmd1 = NULL;
	vars->cmd2 = NULL;
	vars->cmd1_path = NULL;
	vars->cmd2_path = NULL;
	vars->cmd1_args = NULL;
	vars->cmd2_args = NULL;
	return (0);
}
