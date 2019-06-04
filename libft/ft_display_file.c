/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:50:28 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/29 16:34:21 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void	ft_display_file(const char *src)
{
	int		fd;
	int		rd;
	char	buf[BUF_SIZE + 1];

	fd = open(src, O_RDONLY);
	if (fd < 0)
		return ;
	rd = read(fd, buf, BUF_SIZE);
	while (rd)
	{
		buf[rd] = '\0';
		ft_putstr(buf);
		rd = read(fd, buf, BUF_SIZE);
	}
	close(fd);
}
