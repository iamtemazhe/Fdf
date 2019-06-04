/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:46:42 by jwinthei          #+#    #+#             */
/*   Updated: 2019/01/25 21:23:33 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>

wchar_t	*ft_wcsnew(size_t size)
{
	size_t	i;
	wchar_t	*dst;

	if (size + 1 == (size_t)(-1))
		return (NULL);
	dst = (wchar_t*)malloc(sizeof(*dst) * (size + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size + 1)
		dst[i++] = '\0';
	return (dst);
}
