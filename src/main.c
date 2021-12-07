/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:22:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/07 17:23:20 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (!(argc == 5))
	{
		print_error("Wrong number of parameters");
		exit(1);
	}
	else
	{
		init_vars(&vars, argc, argv, envp);
		pipex(&vars);
	}
	return (0);
}
