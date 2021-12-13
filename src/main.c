/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:22:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/12 22:53:39 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc < 5)
	{
		print_error("Too few arguments");
		print_error("Usage: infile \"cmd1\" \"cmd2\" outfile");
		print_error("       infile \"ls -la\" \"tr -d ' '\" outfile");
		exit(1);
	}
	else if (argc > 5)
	{
		print_error("Too many arguments");
		print_error("Usage: infile \"cmd1\" \"cmd2\" outfile");
		print_error("       infile \"ls -la\" \"tr -d ' '\" outfile");
		exit(1);
	}
	else
	{
		init_vars(&vars, argc, argv, envp);
		pipex(&vars);
	}
	return (0);
}
