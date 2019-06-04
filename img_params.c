/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:09:28 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/16 19:36:27 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static double	percent(int start, int end, int current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(t_line line)
{
	int			red;
	int			green;
	int			blue;
	double		percentage;

	if (line.pix.col == line.pix1.col)
		return (line.pix.col);
	if (line.dx > line.dy)
		percentage = percent(line.pix0.x, line.pix1.x, line.pix.x);
	else
		percentage = percent(line.pix0.y, line.pix1.y, line.pix.y);
	red = get_light((line.pix0.col >> 16) & 0xFF,\
							(line.pix1.col >> 16) & 0xFF, percentage);
	green = get_light((line.pix0.col >> 8) & 0xFF,\
							(line.pix1.col >> 8) & 0xFF, percentage);
	blue = get_light(line.pix0.col & 0xFF, line.pix1.col & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void			rotate_img(t_fdf fdf, int *x, int *y, int *z)
{
	int			px;
	int			py;
	int			pz;

	px = *x;
	py = *y;
	pz = *z;
	if (fdf.img.betta)
	{
		*y = py * cos(fdf.img.betta) + pz * sin(fdf.img.betta);
		*z = -py * sin(fdf.img.betta) + pz * cos(fdf.img.betta);
	}
	pz = *z;
	if (fdf.img.alpha)
	{
		*x = px * cos(fdf.img.alpha) + pz * sin(fdf.img.alpha);
		*z = -px * sin(fdf.img.alpha) + pz * cos(fdf.img.alpha);
	}
	px = *x;
	py = *y;
	if (fdf.img.gamma)
	{
		*x = px * cos(fdf.img.gamma) - py * sin(fdf.img.gamma);
		*y = px * sin(fdf.img.gamma) + py * cos(fdf.img.gamma);
	}
}

void			proect_iso_par(t_fdf fdf, int *x, int *y, int *z)
{
	int			px;
	int			py;
	int			pz;
	double		angle;

	px = *x;
	py = *y;
	angle = 0.523599;
	if (fdf.img.proec == ISO)
	{
		*x = (px - py) * cos(angle);
		*y = (px + py) * sin(angle) - *z;
	}
	else if (fdf.img.proec == PAR)
	{
		pz = (*z > 1950) ? 1950 : *z;
		*x = px / (-0.0005 * pz + 1);
		*y = py / (-0.0005 * pz + 1);
		*z = pz / (-0.0005 * pz + 1);
	}
}
