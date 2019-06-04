/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:35:15 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/17 14:09:49 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static int		nb_counter(char *src, int *size)
{
	int			cnb;
	int			pr_nb;

	cnb = 0;
	while (1)
	{
		if (*src == ' ' || *src == '\t' || *src == '\n' ||\
			*src == '\v' || *src == '\f' || *src == '\r' ||\
			*src == '-' || *src == '+' || ('0' <= *src && *src <= '9'))
		{
			pratoi(&src, &pr_nb);
			cnb += (pr_nb > 0) ? 1 : 0;
		}
		else if (*src == ',')
		{
			src++;
			pratoi_hex(&src, &pr_nb);
		}
		else if (!*src)
			break ;
		else
			return (-1);
	}
	*size = (!*size) ? cnb : *size;
	return ((*size == cnb) ? 0 : -1);
}

static int		mapfiller(t_fdf *fdf, char *line, long long i)
{
	int			nb;
	int			pr_nb;
	long long	i0;

	i0 = i--;
	while (++i < fdf->w + i0)
	{
		nb = pratoi(&line, &pr_nb);
		if (pr_nb < 0 || (i == i0 && !pr_nb))
			return (-1);
		fdf->map[i] = nb;
		fdf->maxz = (nb > fdf->maxz) ? nb : fdf->maxz;
		if (*line == ',')
		{
			line++;
			nb = pratoi_hex(&line, &pr_nb);
			if (pr_nb < 0)
				return (-1);
			fdf->map_col[i] = nb;
		}
	}
	return (0);
}

static int		mapwriter(t_fdf *fdf, char *line)
{
	fdf->mod |= (ft_strchr(line, ',')) ? FIXC : 0;
	if (!(fdf->map = (int*)ft_realloc(fdf->map,\
				fdf->w * fdf->h * sizeof(int), NULL, fdf->w * sizeof(int))))
		return (-1);
	if (!(fdf->map_col = (int*)ft_realloc(fdf->map_col,\
				fdf->w * fdf->h * sizeof(int), NULL, fdf->w * sizeof(int))))
		return (-1);
	if (mapfiller(fdf, line, fdf->w * fdf->h))
		return (-1);
	return (0);
}

static int		argreader(const char *file_name, t_fdf *fdf)
{
	int			fd;
	char		*line;

	line = NULL;
	fdf->h = 0;
	fdf->w = 0;
	fdf->mod = 0;
	fdf->map = NULL;
	fdf->map_col = NULL;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (-1);
	while ((fdf->err = get_next_line(fd, &line)))
	{
		if (fdf->err == -1)
			return (ft_strerr(-1, &line));
		if (nb_counter(line, &fdf->w))
			return (ft_strerr(-1, &line));
		if (mapwriter(fdf, line))
			return (ft_strerr(-1, &line));
		fdf->h++;
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}

int				main(int argc, char **argv)
{
	t_fdf		fdf;

	if (argc != 2)
		return (0);
	if (argreader(argv[1], &fdf))
		return (ft_masserr(-1, &fdf.map) + ft_masserr(0, &fdf.map_col));
	fdf.mod = (fdf.mod & FIXC) ? FIXC | DUOC : MCOL;
	fdf.mlx = mlx_init();
	fdf.win.w = WEIGHT;
	fdf.win.h = HEIGHT;
	null_params(&fdf, 0);
	put_img(&fdf);
	mlx_loop(fdf.mlx);
	return (ft_masserr(0, &fdf.map) + ft_masserr(0, &fdf.map_col));
}
