/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:14:54 by gandrade          #+#    #+#             */
/*   Updated: 2021/11/21 19:22:40 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	char	*path;
	int		len;

	path = NULL;
	len = 5;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", len) == 0)
		{
			path = *envp;
			while (path && len--)
				path++;
			return (path);
		}
		envp++;
	}
	return (path);
}
