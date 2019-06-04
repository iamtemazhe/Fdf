/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:25:00 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/15 19:42:39 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *dst, size_t nd, const void *src, size_t ns)
{
	void	*tmp;

	if (!ns)
		return ((!dst) ? NULL : dst);
	if (!dst)
		return (dst = (!src) ? ft_memalloc(ns) : ft_memsub(src, 0, ns));
	if (!(tmp = ft_memjoin(dst, nd, src, ns)))
		return (NULL);
	free(dst);
	return (tmp);
}
