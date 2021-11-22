/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:30:45 by gandrade          #+#    #+#             */
/*   Updated: 2021/11/21 19:37:05 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*tmp;
	size_t	size;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(&s[start]);
	if (size < len)
		len = size;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	tmp = sub;
	while (len--)
		*tmp++ = s[start++];
	*tmp = '\0';
	return (sub);
}
