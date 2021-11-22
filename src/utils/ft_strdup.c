/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:30:21 by gandrade          #+#    #+#             */
/*   Updated: 2021/11/21 12:30:32 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*tmp;

	dup = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	tmp = dup;
	while (*s1)
		*tmp++ = *s1++;
	*tmp = '\0';
	return (dup);
}
