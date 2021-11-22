/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:22:29 by gandrade          #+#    #+#             */
/*   Updated: 2021/11/22 19:31:18 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**splited_path;
	int		i;

	path = get_env_path(envp);
	splited_path = ft_split(path, ':');
	i = 0;
	while (splited_path[i])
	{
		printf("%s\n", splited_path[i]);
		i++;
	}
	clear_double_pointer(splited_path);
	printf("%s\n", path);
	printf("%s\n", *argv);
	printf("%d\n", argc);
	return (0);
}
