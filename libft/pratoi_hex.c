/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pratoi_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:35:58 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/16 20:23:09 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int						pratoi_hex(char **src, int *pr_nb)
{
	unsigned long long	number;

	number = 0;
	*pr_nb = 0;
	while (*src[0] == ' ' || *src[0] == '\t' || *src[0] == '\n' ||\
			*src[0] == '\v' || *src[0] == '\f' || *src[0] == '\r')
		src[0]++;
	src[0] += (*src[0] == '0' && (*(src[0] + 1) == 'x' ||\
									*(src[0] + 1) == 'X')) ? 2 : 0;
	while (('0' <= *src[0] && *src[0] <= '9') ||\
			('a' <= *src[0] && *src[0] <= 'f') ||\
			('A' <= *src[0] && *src[0] <= 'F'))
	{
		*pr_nb += 1;
		number *= 16;
		if ('0' <= *src[0] && *src[0] <= '9')
			number += (int)*src[0] - '0';
		else if ('a' <= *src[0] && *src[0] <= 'f')
			number += (int)*src[0] - 'a' + 10;
		else if ('A' <= *src[0] && *src[0] <= 'F')
			number += (int)*src[0] - 'A' + 10;
		src[0]++;
	}
	*pr_nb = (number > 2147483648) ? -1 : *pr_nb;
	return ((number > 2147483648) ? 0 : (int)number);
}
