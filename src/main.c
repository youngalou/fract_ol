/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 10:15:01 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/22 16:23:13 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_fractal(t_env *env, int (*f)(t_env *env, int x, int y))
{
	int		y;
	int		x;
	int		i;

	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	env->pixels = (int*)mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->endian);
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			i = (*f)(env, x, y);
			env->pixels[x + (y * WIN_W)] = ((i < BOUND) ? i * 500000 : 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
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
		draw_fractal(env, &mandelbrot);
	}
	else if (*(arg + 1) == 'J')
	{
		env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "Julia Set");
		draw_fractal(env, &julia);
		mlx_hook(env->win, 6, 0, mouse_pos, env);
	}
	mlx_key_hook(env->win, key_command, env);
	mlx_loop(env->mlx);
}

t_env	*init_env(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->mlx = 0;
	env->win = 0;
	env->img = 0;
	env->bpp = 4;
	env->sl = 0;
	env->endian = 0;
	env->ca = 0;
	env->cb = 0;
	env->ja = .156;
	env->jb = .8;
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
