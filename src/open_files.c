/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:08:56 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/02 18:57:06 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_files(t_vars *vars)
{
	vars->infile = open(vars->argv[1], O_RDONLY);
	if (vars->infile < 0)
		print_error();
	vars->outfile = open(vars->argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars->outfile < 0)
	{
		close(vars->infile);
		print_error();
	}
	return (0);
}
