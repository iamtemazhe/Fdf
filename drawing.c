/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:35:15 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/17 13:50:43 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void		calc_line_param(t_fdf fdf, t_line *line)
{
	line->err = 0;
	rotate_img(fdf, &line->pix0.x, &line->pix0.y, &line->pix0.z);
	rotate_img(fdf, &line->pix1.x, &line->pix1.y, &line->pix1.z);
	if (fdf.img.proec)
		proect_iso_par(fdf, &line->pix0.x, &line->pix0.y, &line->pix0.z);
	if (fdf.img.proec)
		proect_iso_par(fdf, &line->pix1.x, &line->pix1.y, &line->pix1.z);
	line->pix0.x += fdf.img.w / 2 + fdf.img.mvx;
	line->pix1.x += fdf.img.w / 2 + fdf.img.mvx;
	line->pix0.y += fdf.img.h / 2 + fdf.img.mvy;
	line->pix1.y += fdf.img.h / 2 + fdf.img.mvy;
	line->mod = (line->pix0.x == line->pix1.x ||\
				line->pix0.y == line->pix1.y) ? 1 : 0;
	line->dx = ft_abs(line->pix1.x - line->pix0.x);
	line->dy = ft_abs(line->pix1.y - line->pix0.y);
	line->dirx = (line->pix1.x - line->pix0.x >= 0) ? 1 : -1;
	line->diry = (line->pix1.y - line->pix0.y >= 0) ? 1 : -1;
	line->pix.x = line->pix0.x;
	line->pix.y = line->pix0.y;
	line->pix.z = line->pix0.z;
	line->pix.col = line->pix0.col;
}

static void		draw_line(t_fdf fdf, t_line line)
{
	calc_line_param(fdf, &line);
	while (1)
	{
		if (line.pix.x == line.pix1.x && line.pix.y == line.pix1.y)
			break ;
		line.pix.col = get_color(line);
		if ((0 <= line.pix.x && line.pix.x < fdf.img.w) &&\
			(0 <= line.pix.y && line.pix.y < fdf.img.h))
			fdf.img.cp[line.pix.x + (fdf.img.w * line.pix.y)] = line.pix.col;
		if (line.dy > line.dx)
		{
			line.err += line.dx;
			line.pix.x += (2 * line.err >= line.dy) ? line.dirx : 0;
			line.err -= (2 * line.err >= line.dy) ? line.dy : 0;
			line.pix.y += line.diry;
		}
		else
		{
			line.err += line.dy;
			line.pix.y += (2 * line.err >= line.dx) ? line.diry : 0;
			line.err -= (2 * line.err >= line.dx) ? line.dx : 0;
			line.pix.x += line.dirx;
		}
	}
}

static void		pix_color(t_fdf fdf, t_line *line, int col0, int col1)
{
	if (fdf.mod & MCOL)
	{
		line->pix0.col = 0x006600 + line->pix0.z * 0x33ff + line->col;
		line->pix1.col = 0x006600 + line->pix1.z * 0x33ff + line->col;
	}
	else if (fdf.mod & DUOC)
	{
		line->pix0.col = 0x006600 + ((line->pix0.z / line->zoom) %\
							fdf.maxz) * 0x3300 + line->col;
		line->pix1.col = 0x006600 + ((line->pix1.z / line->zoom) %\
							fdf.maxz) * 0x3300 + line->col;
	}
	else if (fdf.mod & MONOC)
	{
		line->pix0.col = 0x006600 + line->col;
		line->pix1.col = 0x006600 + line->col;
	}
	if (fdf.mod & FIXC)
	{
		line->pix0.col = (col0) ? col0 : line->pix0.col;
		line->pix1.col = (col1) ? col0 : line->pix1.col;
	}
}

void			img_maker_x(t_fdf fdf)
{
	int			x;
	int			y;

	y = fdf.h;
	while (--y >= 0)
	{
		fdf.line.pix0.y = y * fdf.img.step - fdf.img.hp;
		fdf.line.pix1.y = y * fdf.img.step - fdf.img.hp;
		x = fdf.w;
		while (--x >= 1)
		{
			fdf.line.pix0.x = (x - 1) * fdf.img.step - fdf.img.wp;
			fdf.line.pix1.x = x * fdf.img.step - fdf.img.wp;
			fdf.line.pix0.z = fdf.map[y * fdf.w + x - 1] * fdf.line.zoom;
			fdf.line.pix1.z = fdf.map[y * fdf.w + x] * fdf.line.zoom;
			pix_color(fdf, &fdf.line, fdf.map_col[y * fdf.w + x - 1],\
											fdf.map_col[y * fdf.w + x]);
			fdf.line.pix0.z = fdf.map[y * fdf.w + x - 1] *\
									fdf.line.zoom * fdf.img.step / 0x7f;
			fdf.line.pix1.z = fdf.map[y * fdf.w + x] *\
									fdf.line.zoom * fdf.img.step / 0x7f;
			draw_line(fdf, fdf.line);
		}
	}
}

void			img_maker_y(t_fdf fdf)
{
	int			x;
	int			y;

	x = fdf.w;
	while (--x >= 0)
	{
		fdf.line.pix0.x = x * fdf.img.step - fdf.img.wp;
		fdf.line.pix1.x = x * fdf.img.step - fdf.img.wp;
		y = fdf.h;
		while (--y >= 1)
		{
			fdf.line.pix0.y = (y - 1) * fdf.img.step - fdf.img.hp;
			fdf.line.pix1.y = y * fdf.img.step - fdf.img.hp;
			fdf.line.pix0.z = fdf.map[(y - 1) * fdf.w + x] * fdf.line.zoom;
			fdf.line.pix1.z = fdf.map[y * fdf.w + x] * fdf.line.zoom;
			pix_color(fdf, &fdf.line, fdf.map_col[(y - 1) * fdf.w + x],\
											fdf.map_col[y * fdf.w + x]);
			fdf.line.pix0.z = fdf.map[(y - 1) * fdf.w + x] *\
									fdf.line.zoom * fdf.img.step / 0x7f;
			fdf.line.pix1.z = fdf.map[y * fdf.w + x] *\
									fdf.line.zoom * fdf.img.step / 0x7f;
			draw_line(fdf, fdf.line);
		}
	}
}
