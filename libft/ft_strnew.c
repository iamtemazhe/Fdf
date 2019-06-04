/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:46:42 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/20 18:07:57 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*dst;

	if (size + 1 == (size_t)(-1))
		return (NULL);
	dst = (char*)malloc(size + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size + 1)
		dst[i++] = '\0';
	return (dst);
}
