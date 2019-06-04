/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:19:25 by jwinthei          #+#    #+#             */
/*   Updated: 2018/12/11 18:38:05 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_retdel(int retv, char ***str, int fd, char **line)
{
	int	i;
	int	j;

	if (retv == 1)
		return (retv);
	i = -1;
	j = 0;
	ft_strdel(&str[0][fd]);
	while (++i <= MAX_FD && *str)
		if (str[0][i])
			j++;
	if (!j && *str)
		ft_strdel(*str);
	if (retv < 0)
		ft_strdel(line);
	return (retv);
}

static int		ft_chrfinder(char **line, char ***str, int fd, char c)
{
	size_t	l[2];
	char	*tmp;

	if (!(l[0] = ft_strlen(str[0][fd])))
		return (0);
	l[1] = 0;
	if ((tmp = ft_strchr(str[0][fd], c)))
		l[1] = (size_t)(tmp - str[0][fd]) + 1;
	if (!((tmp = ft_strdup(str[0][fd])) &&\
		(*line = ft_strrealloc(*line, str[0][fd], l[1] ? l[1] - 1 : l[0]))))
		return (ft_retdel(-1, str, fd, line));
	ft_memmove(str[0][fd], &tmp[l[1] ? l[1] : l[0]], l[0]);
	free(tmp);
	return (l[1] ? 1 : 0);
}

static int		ft_strnnew(char ***str, int fd, char **line)
{
	if (!*str)
		if (!(*str = ft_nstrnew(MAX_FD)))
			return (-1);
	if (!str[0][fd])
		if (!(str[0][fd] = ft_strnew(BUFF_SIZE)))
			return (ft_retdel(-1, str, fd, line));
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			rd[2];
	static char	**str = NULL;

	if (MAX_FD < fd || fd < 0 || !line)
		return (-1);
	if ((rd[1] = ft_strnnew(&str, fd, line)) != 1)
		return (rd[1]);
	while (1)
	{
		if (!*str[fd])
		{
			if ((rd[0] = read(fd, str[fd], BUFF_SIZE)) == -1)
				return (ft_retdel(rd[0], &str, fd, line));
			str[fd][rd[0]] = '\0';
			if (!rd[0])
				return (ft_retdel(rd[1] ? 0 : 1, &str, fd, line));
		}
		if (*str[fd] && rd[1])
			*line = NULL;
		if ((rd[1] = ft_chrfinder(line, &str, fd, '\n')))
			return (rd[1]);
	}
	return (0);
}
