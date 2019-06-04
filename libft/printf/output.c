/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:56:24 by hgysella          #+#    #+#             */
/*   Updated: 2019/02/07 17:56:04 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write(t_pf *pf, int k, char c)
{
	pf->str[k++] = c;
	return (k);
}

static int	ft_width(t_pf *pf, int k, int len_s, short int sgn)
{
	char	c;

	c = (pf->flg & FLG0 && !(pf->flg & MACC)) ? '0' : ' ';
	pf->wid = (sgn) ? (pf->wid - 1) : pf->wid;
	if (pf->tpc == 'd' || pf->tpc == 'f' || pf->tpc == 'g' || pf->tpc == 'e')
		pf->wid = ((pf->flg & FLGP) && !sgn) ? (pf->wid - 1) : pf->wid;
	pf->wid = ((pf->flg & FLGE) && !(pf->flg & FLGP)) ? (pf->wid - 1) : pf->wid;
	pf->wid = ((pf->flg & FLGS) && pf->tpc == 'o') ? (pf->wid - 1) : pf->wid;
	pf->wid = ((pf->flg & FLGS) && pf->tpc == 'x') ? (pf->wid - 2) : pf->wid;
	pf->wid = (pf->tpc == 'p') ? (pf->wid - 2) : pf->wid;
	if (pf->tpc == 'f')
	{
		pf->wid -= pf->acc + len_s + 1;
		pf->wid += (pf->flg & MACC && !pf->acc) ? 1 : 0;
	}
	else
		pf->wid -= (pf->acc > len_s) ? pf->acc : len_s;
	while (pf->wid-- > 0)
		k = ft_write(pf, k, c);
	return (k);
}

static int	ft_precision(t_pf *pf, int k, int len_s)
{
	if (pf->tpc == 'd' || pf->tpc == 'i' || pf->tpc == 'u' ||\
		pf->tpc == 'o' || pf->tpc == 'x' || pf->tpc == 'p')
	{
		if (pf->tpc == 'o' && (pf->flg & FLGS))
			pf->acc--;
		while (pf->acc-- > len_s)
			k = ft_write(pf, k, '0');
	}
	return (k);
}

static int	sharp_analis(int k, t_pf *pf)
{
	if (pf->flg & FLGS)
	{
		if (pf->tpc == 'o' && (!(pf->flg & MNUL) || (pf->flg & MACC)))
			k = ft_write(pf, k, '0');
		if (pf->tpc == 'x' && !(pf->flg & MNUL))
		{
			k = ft_write(pf, k, '0');
			k = (pf->flg & TYPUP) ? ft_write(pf, k, 'X') : ft_write(pf, k, 'x');
		}
	}
	if (pf->tpc == 'p')
	{
		k = ft_write(pf, k, '0');
		k = ft_write(pf, k, 'x');
	}
	return (k);
}

int			ft_pr_left(t_pf *pf, short int sgn, int len_s)
{
	int		k;

	k = 0;
	if (pf->tpc == 'd' || pf->tpc == 'i' || pf->tpc == 'f' ||\
								pf->tpc == 'e' || pf->tpc == 'g')
	{
		if ((pf->flg & FLGP) && (pf->flg & FLG0))
			k = (sgn) ? ft_write(pf, k, '-') : ft_write(pf, k, '+');
		k = ((pf->flg & FLGE) && !(pf->flg & FLGP) && (!sgn)) ?
			ft_write(pf, k, ' ') : k;
		k = (sgn && (pf->flg & FLG0) && !(pf->flg & FLGP))\
			? ft_write(pf, k, '-') : k;
	}
	if ((pf->tpc == 'o' || pf->tpc == 'x') && (pf->flg & FLG0))
		k = sharp_analis(k, pf);
	k = (!(pf->flg & FLGM)) ? (ft_width(pf, k, len_s, sgn)) : k;
	k = (pf->tpc == 'p') ? sharp_analis(k, pf) : k;
	if (pf->tpc == 'd' || pf->tpc == 'i' || pf->tpc == 'f' ||\
		pf->tpc == 'e' || pf->tpc == 'g')
		if ((pf->flg & FLGP || sgn) && !(pf->flg & FLG0))
			k = (sgn) ? ft_write(pf, k, '-') : ft_write(pf, k, '+');
	if ((pf->tpc == 'o' || pf->tpc == 'x') && !(pf->flg & FLG0))
		k = sharp_analis(k, pf);
	k = ft_precision(pf, k, len_s);
	return (k);
}
