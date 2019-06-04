/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmasserr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:50:17 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/16 16:50:24 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_nmasserr(int retv, int ***nm, size_t n)
{
	if (!(nm && *nm))
		return (retv);
	while (n--)
		ft_masserr(0, &nm[0][n]);
	free(*nm);
	*nm = NULL;
	return (retv);
}
