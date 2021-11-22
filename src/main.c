/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:22:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/11/22 17:46:22 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**splited_path;

	path = get_path(envp);
	splited_path = ft_split(path, ':');
	while (*splited_path)
	{
		printf("%s\n", *splited_path);
		ft_strclear(splited_path);
		splited_path++;
	}
	printf("%s\n", path);
	printf("%s\n", *argv);
	printf("%d\n", argc);
	return (0);
}
