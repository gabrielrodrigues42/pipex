/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:42:16 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/09 19:18:07 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	has_path(char *cmd);
static char	*join_cmd_path(char *cmd, char **path_splited);

char	*get_cmd_path(char *cmd, char **path_splited)
{
	char	*cmd_path;
	char	*tmp;

	cmd_path = NULL;
	if (cmd)
	{
		if (has_path(cmd) == 1 && access(cmd, X_OK) == 0)
			cmd_path = ft_strdup(cmd);
		else if (has_path(cmd) == 1 && !(access(cmd, X_OK) == 0))
		{
			tmp = ft_strjoin("no such file or directory: ", cmd);
			print_error(tmp);
			free(tmp);
		}
		else
			cmd_path = join_cmd_path(cmd, path_splited);
	}
	else
		print_error("command not found: ");
	return (cmd_path);
}

static char	*join_cmd_path(char *cmd, char **path_splited)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	tmp = ft_strjoin("/", cmd);
	cmd_path = NULL;
	i = 0;
	while (path_splited[i])
	{
		cmd_path = ft_strjoin(path_splited[i], tmp);
		if (access(cmd_path, X_OK) == 0)
			break ;
		free (cmd_path);
		cmd_path = NULL;
		i++;
	}
	free(tmp);
	if (!cmd_path)
	{
		tmp = ft_strjoin("command not found: ", cmd);
		print_error(tmp);
		free(tmp);
	}
	return (cmd_path);
}

static int	has_path(char *cmd)
{
	int	has_path;

	has_path = 0;
	if (ft_strncmp(cmd, "/", 1) == 0 || ft_strncmp(cmd, "./", 2) == 0
		|| ft_strncmp(cmd, "../", 3) == 0)
		has_path = 1;
	return (has_path);
}
