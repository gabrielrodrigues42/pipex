/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclear2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:02:42 by gandrade          #+#    #+#             */
/*   Updated: 2021/12/10 12:20:48 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_strclear(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_strclear2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_strclear(&str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
