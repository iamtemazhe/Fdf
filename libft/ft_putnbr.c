/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:55:48 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/26 19:38:02 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 1;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	else
		nbr = n;
	while (n /= 10)
		i *= 10;
	while (i)
	{
		ft_putchar((char)(nbr / i) + '0');
		nbr %= i;
		i /= 10;
	}
}
