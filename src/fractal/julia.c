/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:51:21 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 19:56:28 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	draw_julia_row(t_mlx_data *mlx, int y, float z_imag);

/*
	Julia Examples Values
	c_real = -0.7;
	c_imag = 0.28015
	----------------------
	c_real = 0.285;
	float c_imag = -0.01;
	----------------------
*/

void	draw_julia(t_mlx_data *mlx, int first_time)
{
	float	imag_factor;
	float	z_imag;
	int		y;

	imag_factor = (mlx->max_imag - mlx->min_imag) / 580;
	y = 0;
	z_imag = 1;
	while (y < 580)
	{
		z_imag = mlx->max_imag - y * imag_factor;
		draw_julia_row(mlx, y, z_imag);
		y++;
	}
	if (first_time)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	}
}

void	draw_julia_row(t_mlx_data *mlx, int y, float z_imag)
{
	float		real_factor;
	float		z_real;
	int			x;
	int			iter;
	t_complex	c;

	real_factor = (mlx->max_real - mlx->min_real) / 580;
	x = 0;
	while (x < 580)
	{
		z_real = mlx->min_real + x * real_factor;
		c.real = z_real;
		c.imag = z_imag;
		iter = iterator(c, mlx->max_iterations);
		put_pixel_to_image(&mlx->img, x, y, get_color(mlx, mlx->color, iter));
		x++;
	}
}
