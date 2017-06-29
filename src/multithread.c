/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:25:11 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/29 12:44:47 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	multithread(t_env *env)
{
	int		i;

	if (env->drawn)
	{
		mlx_clear_window(env->mlx, env->win);
		env->drawn = 0;
	}
	i = 0;
	while (i < 10)
	{
		pthread_create(&env->tid[i], NULL, find_thread, env);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_join(env->tid[i], NULL);
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	env->drawn = 1;
}

void	*find_thread(void *env)
{
	t_env	*e;
	int		i;

	e = (t_env*)env;
	i = 0;
	while (i < 10)
	{
		if (pthread_equal(pthread_self(), e->tid[i]))
			draw_fractal(e, i * (WIN_H / 10), i * (WIN_H / 10) + (WIN_H / 10));
		i++;
	}
	return (0);
}
