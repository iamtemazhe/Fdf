/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:06:49 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/20 18:09:30 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strfnew(size_t size, char c)
{
	size_t	i;
	char	*dst;

	if (size + 1 == (size_t)(-1))
		return (NULL);
	dst = (char*)malloc(size + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
		dst[i++] = c;
	dst[i] = '\0';
	return (dst);
}
