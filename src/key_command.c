/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:34:38 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/29 15:54:51 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		key_command(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	if (key == 48)
		reset(env);
	if (key == 27 || key == 78 || key == 24 || key == 69)
	{
		if ((key == 27 || key == 78) && env->bound > 0)
			env->bound -= 5;
		if (key == 24 || key == 69)
			env->bound += 5;
		multithread(env);
	}
	if (key >= 71 && key <= 91)
		key_color(key, env);
	if (key == 13 || (key >= 0 && key <= 2))
	{
		(key == 13) ? env->y_trans += SHIFT : 0;
		(key == 1) ? env->y_trans -= SHIFT : 0;
		(key == 0) ? env->x_trans += SHIFT : 0;
		(key == 2) ? env->x_trans -= SHIFT : 0;
		multithread(env);
	}
	if (key == 49)
		env->lock = (env->lock == 0) ? 1 : 0;
	return (0);
}

void	key_color(int key, t_env *env)
{
	if (key == 83)
		env->r -= 0x010000;
	if (key == 84)
		env->r += 0x010000;
	if (key == 86)
		env->g -= 0x000100;
	if (key == 87)
		env->g += 0x000100;
	if (key == 89)
		env->b -= 0x000001;
	if (key == 91)
		env->b += 0x000001;
	if (key == 71)
	{
		env->r = 0x030000;
		env->g = 0x000300;
		env->b = 0x000003;
	}
	multithread(env);
}

int		mouse_sierp(int key, int x, int y, t_env *env)
{
	if (key == 4 || key == 5)
	{
		env->x0 += (x - env->x_trans) / env->zoom;
		env->y0 += (y - env->y_trans) / env->zoom;
		env->zoom *= ((key == 4) ? Z_MULT : 1 / Z_MULT);
		env->x_trans = x;
		env->y_trans = y;
		multithread(env);
	}
	return (0);
}

int		mouse_julia(int key, int x, int y, t_env *env)
{
	if (key == 4 || key == 5)
	{
		env->x0 += (x - env->x_trans) / ((WIN_W / 4) * env->zoom);
		env->y0 += (y - env->y_trans) / ((WIN_W / 4) * env->zoom);
		env->zoom *= ((key == 4) ? Z_MULT : 1 / Z_MULT);
		env->x_trans = x;
		env->y_trans = y;
		multithread(env);
	}
	return (0);
}

int		mouse_pos(int x, int y, t_env *env)
{
	if ((x == env->ja && y == env->jb) || !env->lock)
		return (0);
	env->ja = ((((double)x - WIN_W) / (WIN_W / 2)) + 1);
	env->jb = ((((double)y - WIN_H) / (WIN_H / 2)) + 1);
	multithread(env);
	return (0);
}
