/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 10:15:01 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/22 13:36:24 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		mandelbrot(t_env *env, double x, double y)
{
	int		i;
	double	a;
	double	b;
	double	aa;
	double	bb;

	a = (x - (WIN_W / 2)) / (WIN_W / 4);
	b = (y - (WIN_H / 2)) / (WIN_H / 4);
	env->ca = a;
	env->cb = b;
	i = 0;
	while (i < 100 && a + b <= 16)
	{
		aa = (a * a) - (b * b);
		bb = 2 * a * b;
		a = aa + env->ca;
		b = bb + env->cb;
		i++;
	}
	return (i);
}

void	draw_fractal(t_env *env)
{
	double	y;
	double	x;
	int		i;
	int		color;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			i = mandelbrot(env, x, y);
			color = ((i < 100) ? i * 500000 : 0);
			mlx_pixel_put(env->mlx, env->win, x, y, color);
			x++;
		}
		y++;
	}
}	

void	call_set(t_env *env, char *arg)
{
	env->mlx = mlx_init();
	if (!*(arg + 1))
	{
		ft_printf("%{red}Invalid arguments.%{eoc}\nUsage:\t./fractol [-M]\n");
		return ;
	}
	if (*(arg + 1) == 'M')
	{
		env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "Mandelbrot Set");
		draw_fractal(env);
	}
	mlx_loop(env->mlx);
}

t_env	*init_env(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->mlx = 0;
	env->win = 0;
	env->ca = 0;
	env->cb = 0;
	return (env);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
	{
		ft_printf("%{red}Invalid arguments.%{eoc}\nUsage:\t./fractol [-M]\n");
		return (0);
	}
	if (*argv[1] == '-')
	{
		env = init_env();
		call_set(env, argv[1]);
	}
	return (0);
}
