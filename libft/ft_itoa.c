/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:21:19 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/27 17:42:34 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(unsigned int nbr)
{
	size_t	i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int				i;
	int				sign;
	unsigned int	nbr;
	char			*str;

	sign = 0;
	if (n < 0)
	{
		nbr = -n;
		sign = 1;
	}
	else
		nbr = n;
	i = ft_nbrlen(nbr) + sign;
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	while (--i >= sign)
	{
		str[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
