/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchari_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:16:03 by jwinthei          #+#    #+#             */
/*   Updated: 2019/02/02 15:19:01 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchari_fd(int c, int fd)
{
	char	ds[4];

	if (fd < 0)
		return (0);
	if (c < 0x80)
		return (write(fd, &c, 1));
	else if (c < 0x00000800)
	{
		ds[1] = 0x80 | (c & 0x3F);
		ds[0] = 0xC0 | ((c >> 6) & 0x1F);
		return (write(fd, ds, 2));
	}
	else
	{
		ds[2] = 0x80 | (c & 0x3F);
		ds[1] = 0x80 | ((c >> 6) & 0x3F);
		ds[0] = 0xE0 | ((c >> 12) & 0xF);
		return (write(fd, ds, 3));
	}
}
