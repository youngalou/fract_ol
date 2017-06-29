/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:29:11 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/29 10:45:07 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_fractal(t_env *env, int y, int end_y)
{
	int		x;
	int		i;

	while (y < end_y)
	{
		x = 0;
		while (x < WIN_W)
		{
			i = env->f(env, x, y);
			env->pixels[x + (y * WIN_W)] = ((i < BOUND) ? i * 500000 : 0);
			x++;
		}
		y++;
	}
}

int		sierpinski(t_env *env, int x, int y)
{
	int		i;
	int		a;
	int		b;

	a = abs(x) / env->zoom;
	b = abs(y) / env->zoom;
	i = 0;
	while (i < BOUND && (a > 0 || b > 0))
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
	while (i < BOUND && a + b <= 16)
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
	double	a;
	double	b;
	double	aa;
	double	bb;
	double	ca;
	double	cb;

	a = ((double)x - env->x_trans) / ((WIN_W / 4) * env->zoom) + env->x0;
	b = ((double)y - env->y_trans) / ((WIN_H / 4) * env->zoom) + env->y0;
	ca = a;
	cb = b;
	i = 0;
	while (i < BOUND && a + b <= 16)
	{
		aa = (a * a) - (b * b);
		bb = 2 * a * b;
		a = aa + ca;
		b = bb + cb;
		i++;
	}
	return (i);
}
