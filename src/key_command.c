/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:34:38 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/27 14:49:43 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h> //remove!

//		ja			jb
	//.385,		.311667
	//-.76333,	-.211667
	//-.581667, .556667
	//-.025,	.763333
	//.341667,	-.068333
	//.266667,	.003333
	//.261667	.001667


int		key_command(int key, t_env *env)
{
	//ft_printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 48)
		reset(env);
	if (key >= 24 && key <= 78)
	{
		if (key == 24 || key == 69)
			env->zoom /= 2;
		if (key == 27 || key == 78)
			env->zoom *= 2;
		multithread(env);
	}
	if (key == 13 || (key >= 0 && key <= 2))
	{
		(key == 13) ? env->y_trans += env->zoom * 10 : 0;
		(key == 1) ? env->y_trans -= env->zoom * 10 : 0;
		(key == 0) ? env->x_trans += env->zoom * 10 : 0;
		(key == 2) ? env->x_trans -= env->zoom * 10 : 0;
		multithread(env);
	}
	return (0);
}

int		mouse_sierp(int key, int x, int y, t_env *env)
{
	if (key == 4 || key == 5)
	{
		//printf("%d\t%d\n", x, y);
		if (key == 4)
		{
			env->zoom *= 1.346;
			env->x0 += x / (4 / env->zoom);
			env->y0 += y / (4 / env->zoom);
		}
		if (key == 5)
			env->zoom /= 1.333333;
		if (env->zoom >= 8 || env->zoom <= .125)
		{
			env->zoom = 1;
			env->x0 = x / 1.333333;
			env->y0 = y / 1.333333;
		}
		multithread(env);
	}
	return (0);
}

int		mouse_julia(int key, int x, int y, t_env *env)
{
	if (key == 4 || key == 5)
	{
		if (key == 4)
		{
			env->zoom *= 1.05;
			env->x0 += (x - HALF_W + env->x_trans) * (env->zoom / 21);
			env->y0 += (y - HALF_H + env->y_trans) * (env->zoom / 21);
		}
		if (key == 5)
		{
			env->zoom /= 1.05;
			env->x0 -= (x - HALF_W + env->x_trans) * (env->zoom / 21);
			env->y0 -= (y - HALF_H + env->y_trans) * (env->zoom / 21);
		}
		multithread(env);
	}
	return (0);
}

int		mouse_mand(int key, int x, int y, t_env *env)
{
	if (key == 4 || key == 5)
	{
		if (key == 4)
		{
			env->zoom *= 1.1;
			env->x0 += ((x - (WIN_W / 2)) / 11) * env->zoom;
			env->y0 += ((y - (WIN_H / 2)) / 11) * env->zoom;
		}
		if (key == 5)
		{
			env->zoom /= 1.1;
			env->x0 -= ((x - (WIN_W / 2)) / 11) * env->zoom;
			env->y0 -= ((y - (WIN_H / 2)) / 11) * env->zoom;
		}
		multithread(env);
		//mlx_clear_window(env->mlx, env->win);
		//draw_fractal(env, 0 , WIN_H);
		//mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	return (0);
}

int		mouse_pos(int x, int y, t_env *env)
{
	if (x == env->ja && y == env->jb)
		return (0);
	env->ja = (((double)x - WIN_W) / (WIN_W / 2)) + 1;
	env->jb = (((double)y - WIN_H) / (WIN_H / 2)) + 1;
	//printf("%lf\t%lf\n", env->ja, env->jb);
	multithread(env);
	return (0);
}
