/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:21:39 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/06 16:29:21 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**ft_nstrnew(size_t size)
{
	size_t	i;
	char	**dst;

	if (size + 1 == (size_t)(-1))
		return (NULL);
	if (!(dst = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size + 1)
		dst[i++] = NULL;
	return (dst);
}
