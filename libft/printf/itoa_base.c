/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:37:32 by jwinthei          #+#    #+#             */
/*   Updated: 2019/02/07 18:12:24 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	count_len(t_pf *pf, int len_s)
{
	int	i;
	int	t;

	if (pf->tpc == 'a' || pf->tpc == 'g' || pf->tpc == 'e' ||\
							pf->tpc == 'f' || pf->tpc == 'p')
	{
		t = (pf->acc) ? 1 : 0;
		i = ft_max((len_s + pf->acc + t), pf->acc, pf->wid);
	}
	else
		i = ft_max(len_s, pf->acc, pf->wid);
	if (((pf->tpc == 'o' || pf->tpc == 'x') && pf->flg & FLGS)\
			|| pf->tpc == 'p')
		i += 2;
	if (!(pf->str = ft_strnew(i)))
		return (-1);
	return (i);
}

static size_t
	nbr_length(unsigned long long nbr, short int *sgn, int len_b, t_pf *pf)
{
	size_t	i;

	i = 1;
	if (len_b == 10 && (long long)nbr < 0 && pf->tpc != 'u')
	{
		nbr = -nbr;
		*sgn = 1;
		i++;
	}
	while (nbr /= len_b)
		i++;
	return (i);
}

static int
	putstr_itoa(unsigned long long nbr, const char *base, t_pf *pf)
{
	int			ij[2];
	int			len_s;
	int			len_b;
	short int	sgn;

	sgn = 0;
	if (!(len_b = ft_base_analis(base)))
		return (-1);
	if (!(len_s = nbr_length(nbr, &sgn, len_b, pf)) || (pf->flg & MACC &&\
		!nbr && !pf->acc && (pf->tpc == 'd' || pf->tpc == 'u' ||\
		pf->tpc == 'i' || pf->tpc == 'x' || pf->tpc == 'o' || pf->tpc == 'p')))
		len_s = 0;
	if ((ij[0] = count_len(pf, len_s)) == -1)
		return (-1);
	nbr = (sgn) ? -nbr : nbr;
	len_s = (sgn) ? (len_s - 1) : len_s;
	ij[0] = ft_pr_left(pf, sgn, len_s);
	ij[1] = ij[0] + len_s - 1;
	while (len_s-- > 0)
	{
		pf->str[ij[1]--] = base[nbr % len_b];
		nbr /= len_b;
		ij[0]++;
	}
	return (ij[0]);
}

char
	*ft_itoa_base_ll(unsigned long long nbr, char **base, t_pf *pf)
{
	int	i;
	int	w;

	if ((i = putstr_itoa(nbr, *base, pf)) == -1)
		exit(ft_strerr(-3, base));
	w = pf->wid - i;
	i = ((pf->flg & FLGM) && w > 0) ? ft_pr_right(pf, w, i, ' ') : i;
	pf->str[i] = '\0';
	pf->count += write(1, pf->str, i);
	return (pf->str);
}

char
	*ft_itoa_base_ld(long double nbr, char **base, t_pf *pf)
{
	int					i;
	int					len_b;
	unsigned long long	nb;

	if (!(len_b = ft_base_analis(*base)))
		exit(ft_strerr(-3, base));
	pf->acc = (pf->flg & MACC) ? pf->acc : 6;
	nb = nbr_round_ll(nbr, *base, pf, len_b);
	if ((i = putstr_itoa(nb, *base, pf)) == -1)
		exit(ft_strerr(-3, base));
	nb = (unsigned long long)nbr;
	nbr = (nbr < 0) ? -nbr - -nb : nbr - nb;
	if (pf->acc)
		pf->str[i++] = '.';
	while (pf->acc-- > 0)
	{
		nbr *= (long double)len_b;
		pf->str[i++] = base[0][(unsigned long long int)nbr % len_b];
	}
	nb = (unsigned long long)(nbr * len_b) % len_b;
	nbr_round_ld(base[0][nb], *base, pf, i - 1);
	i = ((pf->flg & FLGM) && pf->wid - i > 0) ?\
		ft_pr_right(pf, pf->wid - i, i, ' ') : i;
	pf->count += write(1, pf->str, i);
	return (pf->str);
}
