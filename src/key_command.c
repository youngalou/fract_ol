/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:34:38 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/22 16:06:12 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		key_command(int key, t_env *env)
{
	env = NULL;
	if (key == 53)
		exit(0);
	return (0);
}

int		mouse_pos(int x, int y, t_env *env)
{
	if (x == env->ja && y == env->jb)
		return (0);
	env->ja = (((double)x - WIN_W) / (WIN_W / 2)) + 1;
	env->jb = (((double)y - WIN_H) / (WIN_H / 2)) + 1;
	mlx_clear_window(env->mlx, env->win);
	draw_fractal(env, &julia);
	return (0);
}
