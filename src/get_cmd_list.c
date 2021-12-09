/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:14:28 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/08 21:09:50 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_cmd_args_addrs(char *argv, int cmd_args);
static int	count_cmd_args(char *argv);

char	**get_cmd_list(char *argv)
{
	char	**cmd_args_addrs;
	char	**cmd_list;
	int		cmd_args;
	int		i;

	if (ft_strcmp(argv, "") == 0)
	{
		print_error("command not found: ");
		return (NULL);
	}
	cmd_args = count_cmd_args(argv);
	cmd_args_addrs = get_cmd_args_addrs(argv, cmd_args);
	cmd_list = (char **)malloc((cmd_args + 1) * sizeof(char *));
	i = 0;
	while (i < cmd_args)
	{
		cmd_list[i] = ft_strtrim(cmd_args_addrs[i], " ");
		i++;
	}
	cmd_list[i] = NULL;
	free(cmd_args_addrs);
	return (cmd_list);
}

static char	**get_cmd_args_addrs(char *argv, int cmd_args)
{
	char	**addrs;
	int		not_count;
	int		i;
	int		j;

	addrs = (char **)malloc((cmd_args + 1) * sizeof(char *));
	not_count = 0;
	i = 0;
	j = 0;
	while (argv[i])
	{
		if (!not_count && argv[i] != ' ' && (i == 0 || argv[i - 1] == ' '))
		{
			addrs[j] = &argv[i];
			if (i != 0)
				argv[i - 1] = '\0';
			j++;
		}
		if (argv[i] == '\'')
			not_count = !not_count;
		i++;
	}
	addrs[j] = NULL;
	return (addrs);
}

static int	count_cmd_args(char *argv)
{
	int	cmd_args;
	int	not_count;
	int	i;

	cmd_args = 0;
	not_count = 0;
	i = 0;
	while (argv[i])
	{
		if (!not_count && argv[i] != ' ' && (i == 0 || argv[i - 1] == ' '))
			cmd_args++;
		if (argv[i] == '\'')
			not_count = !not_count;
		i++;
	}
	return (cmd_args);
}
