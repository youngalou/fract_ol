/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 10:16:25 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/27 12:58:26 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/superlibft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <pthread.h>

# define WIN_W	1200
# define WIN_H	1200
# define HALF_W	WIN_W / 2
# define HALF_H	WIN_H / 2
# define BOUND	100

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*pixels;
	int			bpp;
	int			sl;
	int			endian;
	double		ca;
	double		cb;
	double		ja;
	double		jb;
	double		zoom;
	int			x0;
	int			y0;
	int			x_trans;
	int			y_trans;
	int			drawn;
	pthread_t	tid[10];
	int			(*f)(struct s_env *env, int x, int y);
}				t_env;

/*
** --------------- main.c --------------
*/

void			call_set(t_env *env, char *arg);
void			reset(t_env *env);
t_env			*init_env(void);

/*
** --------------- mulithread.c --------------
*/

void			multithread(t_env *env);
void			*find_thread(void *env);

/*
** --------------- fractals.c --------------
*/

void			draw_fractal(t_env *env, int y, int end_y);
int				julia(t_env *env, int x, int y);
int				mandelbrot(t_env *env, int x, int y);
int				sierpinski(t_env *env, int x, int y);

/*
** --------------- key_command.c --------------
*/

int				key_command(int key, t_env *env);
int				mouse_sierp(int key, int x, int y, t_env *env);
int				mouse_julia(int key, int x, int y, t_env *env);
int				mouse_mand(int key, int x, int y, t_env *env);
int				mouse_pos(int x, int y, t_env *env);

#endif
