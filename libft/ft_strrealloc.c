/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:20:00 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/23 17:30:22 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrealloc(char *dst, const char *src, size_t n)
{
	char	*sub;
	char	*tmp;

	if (!src && !dst && !n)
		return (NULL);
	if (!src && !dst && n)
		return (dst = ft_strnew(n));
	if (!src && dst)
		return (dst);
	if (!(sub = ft_strsub(src, 0, n)))
		return (NULL);
	if (!dst)
		return (sub);
	if (!(tmp = ft_strjoin(dst, sub)))
		return (NULL);
	free(dst);
	free(sub);
	return (tmp);
}
