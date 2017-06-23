/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:25:11 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/22 18:25:57 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	multithread(t_env *env)
{
	int		i;

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
			draw_fractal(e, (i * 120), (i * 120) + 120);
		i++;
	}
	return (0);
}
