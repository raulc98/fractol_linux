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

#include "../../includes/fract_ol.h"

void	draw_mandelbrot_row(t_mlx_data *mlx, int y, float c_imag);

void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	unsigned int	*pixel_ptr;

	printf("Por aquiiii");
	pixel_ptr = (unsigned int *)(image->addr
			+ (y * image->line_length) + (x * (image->bpp / 8)));
	*pixel_ptr = color;
}

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
		printf("X: %d ,y: %d\n",x,y);
		printf("iterations: %d\n",mlx->max_iterations);
		iter = mandelbrot(c, mlx->max_iterations);
		printf("ITER: %d\n",iter);
		int color_get = get_color(mlx, mlx->color, iter);
		printf("COLOR_GET: %d\n", color_get);
		if(&mlx->img)
		{
			put_pixel_to_image(&mlx->img, x, y, color_get);
		}else{
			printf("OH,.....");
		}
		x++;
	}
	printf("SALIMOS");
}

int	mandelbrot(t_complex c, int max_iterations)
{
	float	z_real;
	float	z_imag;
	float	temp;
	int		n;

	z_real = 0.0f;
	z_imag = 0.0f;
	temp = 0;
	n = 0;
	while (z_real * z_real + z_imag * z_imag <= 4.0f && n < max_iterations)
	{
		temp = z_real;
		z_real = z_real * z_real - z_imag * z_imag + c.real;
		z_imag = 2.0f * temp * z_imag + c.imag;
		n++;
	}
	return (n);
}
