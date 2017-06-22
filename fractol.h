/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 10:16:25 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/22 15:13:27 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/superlibft.h"
# include "minilibx/mlx.h"
# include <math.h>

# define WIN_W	1200
# define WIN_H	1200
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
}				t_env;

#endif
