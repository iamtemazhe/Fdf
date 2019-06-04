/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrerr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:00:57 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/16 16:49:28 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nstrerr(int retv, char ***ns)
{
	size_t	i;

	i = 0;
	if (!(ns && *ns))
		return (retv);
	while (ns[0][i])
		ft_strdel(&ns[0][i++]);
	ft_strdel(*ns);
	return (retv);
}
