/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 10:15:01 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/29 15:51:16 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	open_mlx(t_env *env, char arg)
{
	if (arg != 'M' && arg != 'J' && arg != 'S')
	{
		ft_printf("%{red}Invalid arguments.%{eoc}\nUsage:\t./fractol [-MJS]\n");
		return ;
	}
	env->mlx = mlx_init();
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	env->pixels = (int*)mlx_get_data_addr(
						env->img, &env->bpp, &env->sl, &env->endian);
	call_set(env, arg);
	mlx_hook(env->win, 2, 0, key_command, env);
	mlx_loop(env->mlx);
}

void	call_set(t_env *env, char arg)
{
	if (arg == 'M')
	{
		env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "Mandelbrot Set");
		env->f = &mandelbrot;
		multithread(env);
		mlx_mouse_hook(env->win, mouse_julia, env);
	}
	else if (arg == 'J')
	{
		env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "Julia Set");
		env->f = &julia;
		multithread(env);
		mlx_mouse_hook(env->win, mouse_julia, env);
		mlx_hook(env->win, 6, 0, mouse_pos, env);
	}
	else if (arg == 'S')
	{
		env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "Sierpinski Carpet");
		env->f = &sierpinski;
		multithread(env);
		mlx_mouse_hook(env->win, mouse_sierp, env);
	}
}

void	reset(t_env *env)
{
	env->bound = 100;
	env->zoom = 1;
	env->x0 = 0;
	env->y0 = 0;
	env->x_trans = HALF_W;
	env->y_trans = HALF_H;
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
	env->bound = 100;
	env->ca = 0;
	env->cb = 0;
	env->ja = .388333;
	env->jb = -.301667;
	env->zoom = 1;
	env->x0 = 0;
	env->y0 = 0;
	env->x_trans = HALF_W;
	env->y_trans = HALF_H;
	env->r = 0x030000;
	env->g = 0x000300;
	env->b = 0x000003;
	env->drawn = 0;
	env->lock = 1;
	return (env);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc > 1 && *argv[1] && *(argv[1] + 1) && *argv[1] == '-')
	{
		env = init_env();
		open_mlx(env, *(argv[1] + 1));
	}
	else
		ft_printf("%{red}Invalid arguments.%{eoc}\nUsage:\t./fractol [-MJS]\n");
	return (0);
}
