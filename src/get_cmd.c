/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:14:28 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/05 13:57:09 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char *argv)
{
	char	*cmd;
	char	*tmp;
	int		i;

	i = 0;
	while (argv[i] != ' ')
		i++;
	tmp = ft_substr(argv, 0, i);
	cmd = ft_strjoin("/", tmp);
	free(tmp);
	if (ft_strcmp(cmd, "/") == 0)
	{
		free(cmd);
		cmd = NULL;
	}
	return (cmd);
}
