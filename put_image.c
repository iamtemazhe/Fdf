/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:35:15 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/16 20:16:33 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void		put_back(t_fdf *fdf)
{
	int			razm;

	fdf->menu.w = fdf->win.w;
	fdf->menu.h = fdf->win.h / 15;
	if (!fdf->menu.p)
	{
		fdf->menu.p = mlx_new_image(fdf->mlx, fdf->menu.w, fdf->menu.h);
		fdf->menu.cp = (int*)mlx_get_data_addr(fdf->menu.p, &fdf->menu.bpp,\
											&fdf->menu.ls, &fdf->menu.end);
	}
	ft_bzero(fdf->menu.cp, fdf->menu.w * fdf->menu.h * sizeof(int));
	razm = fdf->menu.h * fdf->menu.w;
	while (--razm >= 0)
		fdf->menu.cp[razm] = 0x006600 + fdf->line.col;
	mlx_put_image_to_window(fdf->mlx, fdf->win.p, fdf->menu.p, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win.p, fdf->menu.p, 0,\
												fdf->win.h - fdf->menu.h);
}

static void		put_submenu(t_fdf *fdf, int pozh, int col)
{
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w * 0.9, pozh, col,\
														"Colors: [ | ]");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w * 0.9, pozh + 30, col,\
															"Color mode:");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w * 0.9, pozh + 60, col,\
																"Mono  - M");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w * 0.9, pozh + 90, col,\
																"Duo   - D");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w * 0.9, pozh + 120, col,\
																"Color - C");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w * 0.9, pozh + 150, col,\
																"Fixed - F");
}

static void		put_menu(t_fdf *fdf)
{
	int			col;
	int			pozh;

	pozh = fdf->win.h / 12;
	col = 0x006600 + fdf->line.col;
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w / 30, pozh, col,\
									"Move: < | ^ | \\/ | > | mouse left");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w / 30, pozh + 30, col,\
											"Zoom: + | - | mouse scroll");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w / 30, pozh + 60, col,\
											"Rotate x: 8 | 2 | mouse left");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w / 30, pozh + 90, col,\
											"Rotate y: 4 | 6 | mouse left");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w / 30, pozh + 120, col,\
											"Rotate z: 7 | 9 | mouse middle");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w / 30, pozh + 150, col,\
												"Restore default position: 5");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w / 30, pozh + 180, col,\
														"Altitude: * | /");
	mlx_string_put(fdf->mlx, fdf->win.p, fdf->win.w / 30, pozh + 210, col,\
													"Restore defaults: R");
	put_submenu(fdf, pozh, col);
}

void			put_img(t_fdf *fdf)
{
	put_back(fdf);
	fdf->img.w = fdf->win.w;
	fdf->img.h = fdf->win.h - 2 * fdf->menu.h;
	fdf->img.wp = fdf->img.step * (fdf->w - 1) / 2;
	fdf->img.hp = fdf->img.step * (fdf->h - 1) / 2;
	if (!fdf->img.p)
	{
		fdf->img.p = mlx_new_image(fdf->mlx, fdf->img.w, fdf->img.h);
		fdf->img.cp = (int*)mlx_get_data_addr(fdf->img.p, &fdf->img.bpp,\
											&fdf->img.ls, &fdf->img.end);
	}
	ft_bzero(fdf->img.cp, fdf->img.w * fdf->img.h * sizeof(int));
	img_maker_x(*fdf);
	img_maker_y(*fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win.p, fdf->img.p, 0, fdf->menu.h);
	put_menu(fdf);
}
