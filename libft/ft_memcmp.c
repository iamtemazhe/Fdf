/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:24:52 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/26 12:49:38 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *src1, const void *src2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (i < n)
	{
		diff = ((unsigned char *)src1)[i] - ((unsigned char *)src2)[i];
		if (diff != 0)
			break ;
		i++;
	}
	return (diff);
}
