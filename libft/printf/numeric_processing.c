/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 19:10:25 by hgysella          #+#    #+#             */
/*   Updated: 2019/02/07 18:00:00 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_base_analis(const char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] < 48 && base[i] > 122)
			return (0);
		if ((base[i] > 57 && base[i] < 65) || (base[i] > 90 && base[i] < 97))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

unsigned long long		nbr_round_ll(long double nbr, const char *base,\
													t_pf *pf, int len_b)
{
	unsigned long long	plen_b;
	unsigned long long	nb;
	unsigned long long	n;
	long double			d;

	if (!base)
		return (0);
	plen_b = ft_pow(len_b, pf->acc + 1);
	n = (unsigned long long)(nbr * plen_b);
	d = (long double)len_b / (long double)plen_b;
	if ((int)(n % len_b) >= len_b / 2)
		nbr += (nbr < 0) ? (-d) : d;
	nb = (unsigned long long)nbr;
	return (nb);
}

void					nbr_round_ld(unsigned char nbr, const char *base,\
															t_pf *pf, int i)
{
	int			len_b;
	static int	cc = 0;

	len_b = ft_strlen(base);
	if (nbr >= base[len_b / 2])
	{
		if (pf->str[i] + 1 > base[len_b - 1])
		{
			cc++;
			if (pf->acc == cc)
			{
				pf->str[i] = base[1];
				return ;
			}
			pf->str[i] = base[0];
			nbr_round_ld(base[len_b - 1], base, pf, i - 1);
		}
		else
			pf->str[i] += 1;
	}
}

int						ft_max(int a, int b, int c)
{
	int d;

	d = (a > b) ? a : b;
	d = (d > c) ? d : c;
	return (d);
}

char					*base_analis(char *base, t_pf *pf)
{
	int		i;

	if (pf->tpc == 'd' || pf->tpc == 'i' || pf->tpc == 'u' ||\
		pf->tpc == 'e' || pf->tpc == 'f' || pf->tpc == 'g')
		base = ft_strdup("0123456789");
	else if (pf->tpc == 'o')
		base = ft_strdup("01234567");
	else if (pf->tpc == 'a' || pf->tpc == 'x' || pf->tpc == 'p')
		base = ft_strdup("0123456789abcdef");
	else if (pf->tpc == 'b')
		base = ft_strdup("01");
	else
		return (NULL);
	(!base) ? exit(-2) : NULL;
	i = -1;
	if (pf->flg & TYPUP && base)
		while (base[++i])
			base[i] = ft_toupper(base[i]);
	return (base);
}
