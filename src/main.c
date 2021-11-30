/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:22:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/11/29 22:13:52 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (!(argc == 5))
	{
		write(2, "Invalid params\n", 15);
		exit(0);
	}
	vars.infile = open(argv[1], O_RDONLY);
	vars.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars.infile < 0)
	{
		write(2, "Invalid params\n", 15);
		exit(0);
	}
	vars.argc = argc;
	vars.argv = argv;
	vars.envp = envp;
	pipex(&vars);
	return (0);
}
