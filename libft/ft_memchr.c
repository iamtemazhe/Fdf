/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:22:42 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/26 12:43:59 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
		if (((unsigned char *)src)[i++] == (unsigned char)c)
			return (void *)(src + i - 1);
	return (NULL);
}
