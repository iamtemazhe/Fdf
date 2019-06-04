/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_analis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:11:15 by jwinthei          #+#    #+#             */
/*   Updated: 2019/02/07 17:55:38 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double				types_aefg(va_list *ap, int flg)
{
	long double	nb;

	if (flg & MODUL)
		nb = va_arg(*ap, long double);
	else
		nb = va_arg(*ap, double);
	return (nb);
}

static unsigned long long int	types_di(va_list *ap, t_pf *pf)
{
	unsigned long long int	nb;

	if (pf->flg & MODJ)
		nb = va_arg(*ap, intmax_t);
	else if (pf->flg & MOD2 && pf->flg & MODL)
		nb = va_arg(*ap, long long int);
	else if (pf->flg & MODL)
		nb = va_arg(*ap, long int);
	else if (pf->flg & MODZ)
		nb = va_arg(*ap, size_t);
	else if (pf->flg & MOD2 && pf->flg & MODH)
		nb = (signed char)va_arg(*ap, int);
	else if (pf->flg & MODH)
		nb = (short int)va_arg(*ap, int);
	else
		nb = va_arg(*ap, int);
	pf->flg |= (!nb) ? MNUL : 0;
	return (nb);
}

static unsigned long long int	types_ouxb(va_list *ap, t_pf *pf)
{
	unsigned long long int	nb;

	if (pf->flg & MODJ)
		nb = va_arg(*ap, uintmax_t);
	else if (pf->flg & MOD2 && pf->flg & MODL)
		nb = va_arg(*ap, unsigned long long int);
	else if (pf->flg & MODL)
		nb = va_arg(*ap, unsigned long int);
	else if (pf->flg & MODZ)
		nb = va_arg(*ap, size_t);
	else if (pf->flg & MOD2 && pf->flg & MODH)
		nb = (unsigned char)va_arg(*ap, unsigned int);
	else if (pf->flg & MODH)
		nb = (unsigned short)va_arg(*ap, unsigned int);
	else
		nb = va_arg(*ap, unsigned int);
	pf->flg |= (!nb) ? MNUL : 0;
	return (nb);
}

static char						*types_cs(va_list *ap, t_pf *pf)
{
	char	*str;

	str = NULL;
	if (pf->tpc == 'c')
	{
		if ((str = ft_strnew(2)))
			if (!(*str = va_arg(*ap, size_t)))
				pf->flg |= MNUL;
	}
	else if (pf->tpc == 's')
	{
		if (!(str = va_arg(*ap, char*)))
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
	}
	else
	{
		if ((str = ft_strnew(2)))
			*str = pf->tpc;
	}
	return (str);
}

void							type_analis(va_list *ap, t_pf *pf)
{
	char	*base;
	char	*str;
	int		*n;

	base = NULL;
	base = base_analis(base, pf);
	if (pf->tpc == 'd' || pf->tpc == 'i')
		ft_itoa_base_ll(types_di(ap, pf), &base, pf);
	else if (pf->tpc == 'u' || pf->tpc == 'o' || pf->tpc == 'x' ||\
			pf->tpc == 'b')
		ft_itoa_base_ll(types_ouxb(ap, pf), &base, pf);
	else if (pf->tpc == 'p')
		ft_itoa_base_ll((unsigned long long)va_arg(*ap, void*), &base, pf);
	else if (pf->tpc == 'a' || pf->tpc == 'e' || pf->tpc == 'f' ||\
			pf->tpc == 'g')
		ft_itoa_base_ld(types_aefg(ap, pf->flg), &base, pf);
	else if (pf->tpc == 'n' && (n = va_arg(*ap, void*)))
		*n = pf->count;
	else
		(str = types_cs(ap, pf)) ? ft_printstr(&str, pf) : exit(-2);
	ft_strdel(&base);
}
