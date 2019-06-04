/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:46:57 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/16 20:20:50 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int				mouse_release(int keycode, int x, int y, t_fdf *fdf)
{
	if ((keycode == 1 || keycode == 2 || keycode == 3) && x >= 0 && y >= 0)
		mlx_hook(fdf->win.p, 6, 0, NULL, NULL);
	put_img(fdf);
	return (0);
}

int				mouse_move(int x, int y, t_fdf *fdf)
{
	fdf->img.mvx = x - fdf->mouse.mvx;
	fdf->img.mvy = y - fdf->mouse.mvy;
	put_img(fdf);
	return (0);
}

static int		mouse_rot_xy(int x, int y, t_fdf *fdf)
{
	fdf->img.alpha = (x - fdf->mouse.rotx) * M_PI / 180.0 + fdf->mouse.rota;
	fdf->img.betta = (y - fdf->mouse.roty) * M_PI / 180.0 + fdf->mouse.rotb;
	put_img(fdf);
	return (0);
}

static int		mouse_rot_z(int x, int y, t_fdf *fdf)
{
	fdf->img.gamma = (((x > fdf->win.w / 2) ? y - fdf->mouse.roty :\
					fdf->mouse.roty - y) +\
					((y <= fdf->win.h / 2) ? x - fdf->mouse.rotx :\
					fdf->mouse.rotx - x)) * M_PI / 180.0 + fdf->mouse.rotz;
	put_img(fdf);
	return (0);
}

int				mouse_press(int keycode, int x, int y, t_fdf *fdf)
{
	if (keycode == 1 && x >= 0 && y >= 0)
	{
		fdf->mouse.mvx = x - fdf->img.mvx;
		fdf->mouse.mvy = y - fdf->img.mvy;
		mlx_hook(fdf->win.p, 6, 0, &mouse_move, fdf);
	}
	else if ((keycode == 2 || keycode == 3) && x >= 0 && y >= 0)
	{
		fdf->mouse.rotx = x;
		fdf->mouse.roty = y;
		fdf->mouse.rota = fdf->img.alpha;
		fdf->mouse.rotb = fdf->img.betta;
		fdf->mouse.rotz = fdf->img.gamma;
		(keycode == 2) ? mlx_hook(fdf->win.p, 6, 0, &mouse_rot_xy, fdf) :\
							mlx_hook(fdf->win.p, 6, 0, &mouse_rot_z, fdf);
	}
	else if (keycode == 5)
		fdf->img.step -= (fdf->img.step - 1 > 1) ? 1 : 0;
	else if (keycode == 4)
		fdf->img.step += 1;
	put_img(fdf);
	return (0);
}
