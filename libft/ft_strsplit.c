/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:07:22 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/28 17:58:13 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_free(char ***str)
{
	char	**clr;

	if (!(str && *str))
		return (NULL);
	clr = *str;
	while (*clr)
	{
		free(*clr);
		clr++;
	}
	free(*str);
	return (*str = NULL);
}

static size_t		ft_column_counter(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
	return (j);
}

char				**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	i_start;
	char	**str;

	if (!(s && c))
		return (NULL);
	if (!(str = (char**)malloc(sizeof(str) * (ft_column_counter(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		i_start = i;
		while (s[i] && s[i] != c)
			i++;
		if (!(str[j++] = ft_strsub(s, i_start, i - i_start)))
			return (ft_free(&str));
	}
	str[j] = NULL;
	return (str);
}
