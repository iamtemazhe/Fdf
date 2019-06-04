/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:59:35 by jwinthei          #+#    #+#             */
/*   Updated: 2019/01/31 14:19:04 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>

wchar_t	*ft_wcsdup(const wchar_t *src)
{
	size_t	i;
	wchar_t	*wcs;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	if (!(wcs = (wchar_t*)malloc(sizeof(*wcs) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		wcs[i] = src[i];
		i++;
	}
	wcs[i] = '\0';
	return (wcs);
}
