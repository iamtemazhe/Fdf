/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:58:56 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/20 16:00:14 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnendl(const char *s, size_t n)
{
	size_t	i;

	if (n < 1 || !s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		if (!((i + 1) % n))
			ft_putchar('\n');
		i++;
	}
}
