/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:29:11 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/26 11:11:54 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

	a = ((double)x - (WIN_W / 2)) / (WIN_W / 4);
	b = ((double)y - (WIN_H / 2)) / (WIN_H / 4);
	i = 0;
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

	a = ((double)x - (WIN_W / 2)) / (WIN_W / 4) / env->zoom;
	b = ((double)y - (WIN_H / 2)) / (WIN_H / 4) / env->zoom;
	env->ca = a / env->zoom;
	env->cb = b / env->zoom;
	i = 0;
	while (i < BOUND && a + b <= 16)
	{
		aa = (a * a) - (b * b);
		bb = 2 * a * b;
		a = aa + env->ca;
		b = bb + env->cb;
		i++;
	}
	return (i);
}
