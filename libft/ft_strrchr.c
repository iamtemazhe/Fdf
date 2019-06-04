/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:39:40 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/26 13:22:01 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *src, int c)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	while (1)
	{
		if (src[i--] == (char)c)
			return (char*)(src + i + 1);
		if (((int)i) < 0)
			break ;
	}
	return (NULL);
}
