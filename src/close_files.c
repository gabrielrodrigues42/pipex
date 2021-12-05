/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:32:46 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/05 00:15:38 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_files(t_vars *vars)
{
	close(vars->infile);
	close(vars->outfile);
	vars->infile = 0;
	vars->outfile = 0;
}
