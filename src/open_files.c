/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:08:56 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/06 22:19:58 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_vars *vars)
{
	vars->infile = open(vars->argv[1], O_RDONLY);
	vars->outfile = open(vars->argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (vars->infile < 0 || vars->outfile < 0)
	{
		close_files(vars);
		print_error("No such file or directory");
	}
}
