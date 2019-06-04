/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pratoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:52:02 by jwinthei          #+#    #+#             */
/*   Updated: 2019/02/26 20:05:12 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		pratoi(char **src, int *pr_nb)
{
	short int			sign;
	unsigned long long	number;

	number = 0;
	*pr_nb = 0;
	while (*src[0] == ' ' || *src[0] == '\t' || *src[0] == '\n' ||\
			*src[0] == '\v' || *src[0] == '\f' || *src[0] == '\r')
		src[0]++;
	sign = (*src[0] == '-') ? -1 : 1;
	src[0] += (*src[0] == '-' || *src[0] == '+') ? 1 : 0;
	while ('0' <= *src[0] && *src[0] <= '9')
	{
		*pr_nb += 1;
		number *= 10;
		number += ((int)*src[0] - '0');
		src[0]++;
	}
	*pr_nb = ((number > 2147483647 && sign > 0) ||\
			(number > 2147483648 && sign < 0) ||\
			(!*pr_nb && (*src[0] < '0' || '9' < *src[0]))) ? -1 : *pr_nb;
	return (((number > 2147483647 && sign > 0) ||\
			(number > 2147483648 && sign < 0)) ? 0 : (int)number * sign);
}
