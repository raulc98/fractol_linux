/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:24:06 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 20:14:19 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: PODEMOS BORRAR TOOODO ESTO
#include "../../includes/fract_ol.h"

void	draw_mandelbrot_row(t_mlx_data *mlx, int y, float c_imag);

void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	unsigned int	*pixel_ptr;
	pixel_ptr = (unsigned int *)(image->addr
			+ (y * image->line_length) + (x * (image->bpp / 8)));
	*pixel_ptr = color;
}

/**
 * PINTA COORDENADAS EN Y!!!!
 */
//TODO: ES EL MIIIIIIIIISMO METODO QUE EL DE DRAW_JULIA!!!!!!!!!!!!!!
void	draw_mandelbrot(t_mlx_data *mlx, int first_time)
{
	int		y;
	float	c_imag;

	y = 0;
	while (y < 580)
	{
		c_imag = mlx->max_imag - y * ((mlx->max_imag - mlx->min_imag) / 720);
		draw_mandelbrot_row(mlx, y, c_imag);
		y++;
	}
	if (first_time)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	}
}

/**
 * PINTA COORDENADAS EN X!!!!
 */
void	draw_mandelbrot_row(t_mlx_data *mlx, int y, float c_imag)
{
	t_complex	c;
	float		c_real;
	int			iter;
	int			x;

	x = 0;
	while (x < 580)
	{
		c_real = mlx->min_real + x * ((mlx->max_real - mlx->min_real) / 720);
		c.real = c_real;
		c.imag = c_imag;
		iter = iterator_mandelbrot(c, mlx->max_iterations);
		int color_get = get_color(mlx, mlx->color, iter);
		if(&mlx->img)
		{
			put_pixel_to_image(&mlx->img, x, y, color_get);
		}
		x++;
	}
}
