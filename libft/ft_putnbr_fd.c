/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:08:24 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/27 12:11:34 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
	}
	else
		nbr = n;
	while (n /= 10)
		i *= 10;
	while (i)
	{
		ft_putchar_fd((char)(nbr / i) + '0', fd);
		nbr %= i;
		i /= 10;
	}
}
