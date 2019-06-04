/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:12:48 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/27 16:40:41 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((int)n > 0 && src && dst)
	{
		while (i < n - 1)
		{
			if (!src[i])
				break ;
			dst[i] = src[i];
			i++;
		}
		if (i < n)
			dst[i] = '\0';
	}
	while (src && src[i])
		i++;
	return (i);
}
