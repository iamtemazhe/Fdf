/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:04:40 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/16 18:21:32 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "mlx.h"

# define ISO     0x1
# define PAR     0x2
# define MCOL    0x1
# define DUOC    0x2
# define MONOC   0x4
# define FIXC    0x8

# define WEIGHT  2560
# define HEIGHT  1395

typedef struct		s_pix
{
	int				x;
	int				y;
	int				z;
	int				col;
}					t_pix;

typedef struct		s_line
{
	t_pix			pix;
	t_pix			pix0;
	t_pix			pix1;
	int				err;
	int				mod;
	int				dx;
	int				dy;
	int				dirx;
	int				diry;
	int				col;
	int				zoom;
}					t_line;

typedef struct		s_mouse
{
	int				mvx;
	int				mvy;
	long double		rotx;
	long double		roty;
	long double		rota;
	long double		rotb;
	long double		rotz;
}					t_mouse;

typedef struct		s_img
{
	void			*p;
	int				*cp;
	int				bpp;
	int				ls;
	int				end;
	int				w;
	int				h;
	int				wp;
	int				hp;
	int				mvx;
	int				mvy;
	int				step;
	int				proec;
	int				rot;
	long double		alpha;
	long double		betta;
	long double		gamma;
}					t_img;

typedef struct		s_win
{
	void			*p;
	int				w;
	int				h;
}					t_win;

typedef struct		s_fdf
{
	t_line			line;
	t_img			img;
	t_img			menu;
	t_win			win;
	t_mouse			mouse;
	void			*mlx;
	int				w;
	int				h;
	int				mod;
	int				maxz;
	int				*map;
	int				*map_col;
	int				err;
}					t_fdf;

void				img_maker_x(t_fdf fdf);
void				img_maker_y(t_fdf fdf);
void				put_img(t_fdf *fdf);
void				null_params(t_fdf *fdf, int mod);
void				rotate_img(t_fdf fdf, int *x, int *y, int *z);
void				proect_iso_par(t_fdf fdf, int *x, int *y, int *z);

int					get_color(t_line line);
int					mouse_move(int x, int y, t_fdf *fdf);
int					mouse_press(int keycode, int x, int y, t_fdf *fdf);
int					mouse_release(int keycode, int x, int y, t_fdf *fdf);
#endif
