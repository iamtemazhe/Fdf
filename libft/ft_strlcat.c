/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:11:54 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/22 18:34:27 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	j = 0;
	len_src = 0;
	while (dst[j])
		j++;
	len_dst = j;
	while (src[len_src])
		len_src++;
	if (n <= len_dst)
		return (len_src + n);
	while (src[i] && j < n - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (len_src + len_dst);
}
