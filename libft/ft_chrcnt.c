/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:45:20 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/20 17:38:42 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_chrcnt(const char *src, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (src && src[i])
		if (src[i++] == c)
			cnt++;
	return (cnt);
}
