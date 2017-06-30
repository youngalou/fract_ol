/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:29:11 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/29 17:04:31 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_fractal(t_env *env, int y, int end_y)
{
	int		x;
	int		i;
	int		color;

	while (y < end_y)
	{
		x = 0;
		while (x < WIN_W)
		{
			i = env->f(env, x, y);
			color = (i * env->r) + (i * env->g) + (i * env->b);
			env->pixels[x + (y * WIN_W)] = ((i < env->bound) ? color : 0);
			x++;
		}
		y++;
	}
}

int		sierpinski(t_env *env, int x, int y)
{
	int			i;
	intmax_t	a;
	intmax_t	b;

	a = ((x - env->x_trans) / env->zoom) + env->x0;
	b = ((y - env->y_trans) / env->zoom) + env->y0;
	a = imaxabs(a);
	b = imaxabs(b);
	i = 0;
	while (i < env->bound && (a > 0 || b > 0))
	{
		if (a % 3 == 1 && b % 3 == 1)
			return (0);
		a /= 3;
		b /= 3;
		i++;
	}
	return (12);
}

int		julia(t_env *env, int x, int y)
{
	int		i;
	double	a;
	double	b;
	double	aa;
	double	bb;

	i = 0;
	a = ((double)x - env->x_trans) / ((WIN_W / 4) * env->zoom) + env->x0;
	b = ((double)y - env->y_trans) / ((WIN_H / 4) * env->zoom) + env->y0;
	while (i < env->bound && a + b <= 16)
	{
		aa = (a * a) - (b * b);
		bb = 2 * a * b;
		a = aa + env->ja;
		b = bb + env->jb;
		i++;
	}
	return (i);
}

int		mandelbrot(t_env *env, int x, int y)
{
	int		i;
	double	tab[6];

	tab[2] = ((double)x - env->x_trans) / ((WIN_W / 4) * env->zoom) + env->x0;
	tab[3] = ((double)y - env->y_trans) / ((WIN_H / 4) * env->zoom) + env->y0;
	tab[0] = tab[2];
	tab[1] = tab[3];
	i = 0;
	while (i < env->bound && tab[2] + tab[3] <= 16)
	{
		tab[4] = (tab[2] * tab[2]) - (tab[3] * tab[3]);
		tab[5] = 2 * tab[2] * tab[3];
		tab[2] = tab[4] + tab[0];
		tab[3] = tab[5] + tab[1];
		i++;
	}
	return (i);
}
