/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:35:15 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/16 20:21:30 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static int		keyboard_press_2(int keycode, t_fdf *fdf)
{
	if (keycode == 86 || keycode == 88)
		fdf->img.alpha += (keycode == 88) ? M_PI / 45.0 : -M_PI / 45.0;
	else if (keycode == 91 || keycode == 84)
		fdf->img.betta += (keycode == 84) ? M_PI / 45.0 : -M_PI / 45.0;
	else if (keycode == 92 || keycode == 89)
		fdf->img.gamma += (keycode == 92) ? M_PI / 45.0 : -M_PI / 45.0;
	else if (keycode == 87)
		null_params(fdf, 2);
	else if (keycode == 15)
		null_params(fdf, 1);
	else if (keycode == 31)
		fdf->img.proec = 0;
	else if (keycode == 75)
		fdf->line.zoom -= (fdf->line.zoom > 1) ? 1 : 0;
	else if (keycode == 67)
		fdf->line.zoom += 1;
	else if (keycode == 124 || keycode == 123)
		fdf->img.mvx = (keycode == 123) ? fdf->img.mvx - 4 : fdf->img.mvx + 4;
	else if (keycode == 126 || keycode == 125)
		fdf->img.mvy = (keycode == 126) ? fdf->img.mvy - 4 : fdf->img.mvy + 4;
	else if (keycode == 34)
		fdf->img.proec = ISO;
	else if (keycode == 35)
		fdf->img.proec = PAR;
	return (0);
}

static int		keyboard_press(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit(ft_masserr(0, &fdf->map) + ft_masserr(0, &fdf->map_col));
	else if (keycode == 2)
		fdf->mod = (fdf->mod & FIXC) ? FIXC | DUOC : DUOC;
	else if (keycode == 46)
		fdf->mod = (fdf->mod & FIXC) ? FIXC | MONOC : MONOC;
	else if (keycode == 8)
		fdf->mod = (fdf->mod & FIXC) ? FIXC | MCOL : MCOL;
	else if (keycode == 3)
		fdf->mod = (fdf->mod & FIXC) ? fdf->mod & 0x7 : fdf->mod | FIXC;
	else if (keycode == 33)
		fdf->line.col -= (fdf->line.col > 0xfffff) ? 0xfff00 : 0;
	else if (keycode == 30)
		fdf->line.col += 0xfff00;
	else if (keycode == 78)
		fdf->img.step -= (fdf->img.step - 3 > 1) ? 3 : 0;
	else if (keycode == 69)
		fdf->img.step += 3;
	else
		keyboard_press_2(keycode, fdf);
	put_img(fdf);
	return (0);
}

static int		close_win(t_fdf *fdf)
{
	exit(ft_masserr(0, &fdf->map) + ft_masserr(0, &fdf->map_col));
	return (0);
}

void			null_params(t_fdf *fdf, int mod)
{
	if (mod == 0)
	{
		fdf->line.col = 1;
		fdf->img.proec = 0;
		fdf->img.p = NULL;
		fdf->menu.p = NULL;
		fdf->win.p = mlx_new_window(fdf->mlx, fdf->win.w, fdf->win.h, "Fdf");
		mlx_hook(fdf->win.p, 2, 0, &keyboard_press, fdf);
		mlx_hook(fdf->win.p, 17, 0, &close_win, fdf);
		mlx_hook(fdf->win.p, 4, 0, &mouse_press, fdf);
		mlx_hook(fdf->win.p, 5, 0, &mouse_release, fdf);
	}
	if (0 <= mod && mod < 2)
	{
		fdf->line.zoom = 1;
		fdf->img.step = fdf->win.w / (3 * fdf->w);
	}
	if (0 <= mod && mod < 3)
	{
		fdf->img.alpha = 0;
		fdf->img.betta = 0;
		fdf->img.gamma = 0;
		fdf->img.mvx = 0;
		fdf->img.mvy = 0;
	}
}
