/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_double_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:02:42 by gandrade          #+#    #+#             */
/*   Updated: 2021/11/22 19:36:48 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*clear_double_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_strclear(&str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
