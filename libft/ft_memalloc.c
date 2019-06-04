/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:51:05 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/14 18:23:30 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*dst;

	if (!size || !(dst = malloc(size)))
		return (NULL);
	while (size--)
		((unsigned char*)dst)[size] = 0;
	return (dst);
}
