/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:45:21 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/23 14:06:49 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (((size_t)dst) > ((size_t)src) && ((size_t)(dst - src)) <= n)
	{
		i = n;
		while (--i)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	else if (((size_t)dst) != ((size_t)src))
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
