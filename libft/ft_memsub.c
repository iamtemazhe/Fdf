/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:32:04 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/15 19:12:39 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memsub(const void *src, size_t start, size_t n)
{
	void	*data;

	if (!src && !n)
		return (NULL);
	if (!(data = ft_memalloc(n)))
		return (NULL);
	if (!src)
		return (data);
	while (n--)
		((unsigned char *)data)[n] =\
				((unsigned char *)src)[start + n];
	return (data);
}
