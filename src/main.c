/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 10:15:01 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/26 10:56:04 by lyoung           ###   ########.fr       */
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
			i = env->f(env, x + env->x0, y + env->y0);
			env->pixels[x + (y * WIN_W)] = ((i < BOUND) ? i * 500000 : 0);
			x++;
		}
		y++;
	}
}	

void	call_set(t_env *env, char *arg)
{
	if (!*(arg + 1) || (*(arg + 1) != 'M' && *(arg + 1) != 'J' && *(arg + 1) != 'S'))
	{
		ft_printf("%{red}Invalid arguments.%{eoc}\nUsage:\t./fractol [-MJS]\n");
		return ;
	}
	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	env->pixels = (int*)mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->endian);
	if (*(arg + 1) == 'M')
	{
		env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "Mandelbrot Set");
		env->f = &mandelbrot;
		multithread(env);
		mlx_mouse_hook(env->win, mouse_mand, env);
		//draw_fractal(env, 0, WIN_H);
		//mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	}
	else if (*(arg + 1) == 'J')
	{
		env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "Julia Set");
		env->f = &julia;
		multithread(env);
		mlx_hook(env->win, 6, 0, mouse_pos, env);
	}
	else if (*(arg + 1) == 'S')
	{
		env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "Sierpinski Carpet");
		env->f = &sierpinski;
		multithread(env);
		mlx_mouse_hook(env->win, mouse_sierp, env);
	}
	mlx_key_hook(env->win, key_command, env);
	mlx_loop(env->mlx);
}

void	reset(t_env *env)
{
	env->zoom = 1;
	env->x0 = 0;
	env->y0 = 0;
	multithread(env);
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
	env->ja = .295;
	env->jb = .49;
	env->zoom = 1;
	env->x0 = 0;
	env->y0 = 0;
	env->drawn = 0;
	return (env);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
	{
		ft_printf("%{red}Invalid arguments.%{eoc}\nUsage:\t./fractol [-MJS]\n");
		return (0);
	}
	if (*argv[1] == '-')
	{
		env = init_env();
		call_set(env, argv[1]);
	}
	return (0);
}
