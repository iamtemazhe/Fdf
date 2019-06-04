/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:35:21 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/26 15:16:31 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	dst = (char*)malloc(sizeof(*dst) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = f(i, ((char*)s)[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
