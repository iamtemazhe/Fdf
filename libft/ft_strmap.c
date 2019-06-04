/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:27:14 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/26 15:16:12 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	dst = (char*)malloc(sizeof(*dst) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = f(((char*)s)[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
