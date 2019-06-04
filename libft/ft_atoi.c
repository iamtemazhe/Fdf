/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:43:11 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/28 19:01:56 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_atoi(const char *src)
{
	size_t			i;
	unsigned int	number;
	int				sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((src[i] == ' ') || (src[i] == '\t') || (src[i] == '\n') \
			|| (src[i] == '\v') || (src[i] == '\f') || (src[i] == '\r'))
		i++;
	if (src[i] == '-')
		sign = -1;
	if ((src[i] == '-') || (src[i] == '+'))
		i++;
	while ('0' <= src[i] && src[i] <= '9')
	{
		number *= 10;
		number += ((int)src[i++] - '0');
	}
	if (number > 2147483647 && sign == 1)
		return (-1);
	if (number > 2147483648 && sign == -1)
		return (0);
	return ((int)number * sign);
}
