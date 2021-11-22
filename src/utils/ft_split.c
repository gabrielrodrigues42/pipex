/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:57:31 by gandrade          #+#    #+#             */
/*   Updated: 2021/11/22 17:45:53 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	count_sections(char const *s, char c);
static size_t	get_section_len(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**splited;
	size_t	sections;
	size_t	i;

	if (!s)
		return (NULL);
	sections = count_sections(s, c);
	splited = malloc((sections + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	sections = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			splited[sections] = ft_substr(s, i, get_section_len(&s[i], c));
			sections++;
			i = (i + get_section_len(&s[i], c) - 1);
		}
		i++;
	}
	splited[sections] = NULL;
	return (splited);
}

static size_t	count_sections(char const *s, char c)
{
	size_t	sections;
	size_t	i;

	sections = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		sections++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (sections);
}

static size_t	get_section_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}
