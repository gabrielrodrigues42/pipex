/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:14:54 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/06 23:25:22 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_env_path(char **envp)
{
	char	**splited_path;
	char	*path;
	int		len;

	splited_path = NULL;
	path = NULL;
	len = 5;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", len) == 0)
		{
			path = *envp;
			while (path && len--)
				path++;
			splited_path = ft_split(path, ':');
			path = NULL;
			break ;
		}
		envp++;
	}
	return (splited_path);
}
