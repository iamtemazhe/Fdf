/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:40:21 by jwinthei          #+#    #+#             */
/*   Updated: 2019/02/07 18:03:00 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char		*mod_analis(const char *fmt, t_pf *pf)
{
	while (fmt && *fmt)
	{
		if (*fmt == 'h')
			pf->flg |= (pf->flg & MODH) ? (MOD2) : (MODH);
		else if (*fmt == 'l')
			pf->flg |= (pf->flg & MODL) ? (MOD2) : (MODL);
		else if (*fmt == 'L')
			pf->flg |= MODUL;
		else if (*fmt == 'j')
			pf->flg |= MODJ;
		else if (*fmt == 'z')
			pf->flg |= MODZ;
		else
			break ;
		fmt++;
	}
	return (fmt);
}

static const char		*flags_analis(const char *fmt, va_list *ap,\
																t_pf *pf)
{
	pf->wid = 0;
	pf->acc = 0;
	while (fmt && *fmt)
	{
		if (!isflg(*fmt))
			break ;
		pf->flg |= (*fmt == '-') ? FLGM : 0;
		pf->flg |= (*fmt == '+') ? FLGP : 0;
		pf->flg |= (*fmt == ' ') ? FLGE : 0;
		pf->flg |= (*fmt == '#') ? FLGS : 0;
		pf->flg |= (*fmt == '0' && !(pf->flg & MACC) && !pf->wid) ? FLG0 : 0;
		pf->flg |= (*fmt == '.') ? MACC : 0;
		if (*fmt == '.')
		{
			if (ft_isdigit(*(fmt + 1)) || *(fmt + 1) == '*')
				pf->acc = (*(++fmt) == '*') ? va_arg(*ap, int) : patoi(&fmt);
			else
				pf->acc = 0;
		}
		if (!(pf->flg & MACC) && (ft_isdigit(*fmt) || *fmt == '*'))
			pf->wid = (*fmt == '*') ? va_arg(*ap, int) : patoi(&fmt);
		fmt++;
	}
	return (fmt);
}

static const char		*form_analis(const char *fmt, va_list *ap,\
																t_pf *pf)
{
	pf->flg = 0;
	pf->tpc = 0;
	fmt = mod_analis(fmt, pf);
	fmt = flags_analis(fmt, ap, pf);
	pf->flg -= (pf->acc < 0) ? MACC : 0;
	pf->flg |= (pf->wid < 0) ? FLGM : 0;
	pf->wid = (pf->wid < 0) ? -pf->wid : pf->wid;
	fmt = mod_analis(fmt, pf);
	pf->tpc = *fmt;
	pf->flg |= (pf->tpc == 'S' || pf->tpc == 'C' || pf->tpc == 'D' ||\
				pf->tpc == 'O' || pf->tpc == 'F' || pf->tpc == 'U') ? MODL : 0;
	pf->flg |= (pf->tpc < 'a' && pf->tpc != 'P') ? TYPUP : 0;
	pf->tpc += (pf->tpc == 'S' || pf->tpc == 'C' || pf->tpc == 'U' ||\
				pf->tpc == 'D' || pf->tpc == 'O' || pf->tpc == 'I' ||\
				pf->tpc == 'X' || pf->tpc == 'F' || pf->tpc == 'A' ||\
				pf->tpc == 'G' || pf->tpc == 'E') ? 32 : 0;
	pf->flg -= (pf->flg & MACC && pf->flg & FLG0 && (pf->tpc == 'd' ||\
				pf->tpc == 'i' || pf->tpc == 'x' || pf->tpc == 'o')) ? FLG0 : 0;
	type_analis(ap, pf);
	return ((pf->str || pf->tpc == 'n') ? fmt : --fmt);
}

static void				print_str(const char *format, va_list *ap, t_pf *pf)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (*format == '%')
		{
			pf->count += write(1, format - i, i);
			format = form_analis(++format, ap, pf);
			ft_strdel(&pf->str);
			i = 0;
		}
		else if (*format)
			i++;
		else
		{
			pf->count += write(1, format - i, i);
			break ;
		}
		format += (*format) ? 1 : 0;
	}
}

int						ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	t_pf	*pf;
	int		count;

	if (!(format && (pf = (t_pf*)malloc(sizeof(t_pf)))))
		exit(-1);
	pf->str = NULL;
	pf->count = 0;
	va_start(ap, format);
	print_str(format, &ap, pf);
	va_end(ap);
	count = pf->count;
	free(pf);
	return (count);
}
