/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:30:08 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/26 14:06:04 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *src1, const char *src2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (i < n)
	{
		diff = ((unsigned char *)src1)[i] - ((unsigned char *)src2)[i];
		if (diff != 0 || src1[i] == '\0' || src2[i] == '\0')
			break ;
		i++;
	}
	return (diff);
}
