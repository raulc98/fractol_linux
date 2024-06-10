/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:58:56 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 19:50:40 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	zoom(t_mlx_data *mlx)
{
	printf("ZOOOM : %d\n",mlx->zoom);
	if (mlx->zoom < 150)
	{
		mlx->zoom += 1;
		mlx->step /= 1.12;
		zoom_fractal(mlx, 580 / 2, 580 / 2, 1.0 / 0.87);
	}
}

void	zoom_out(t_mlx_data *mlx)
{
	if (mlx->zoom > -5)
	{
		mlx->zoom -= 1;
		mlx->step *= 1.12;
		zoom_fractal(mlx, 580 / 2, 580 / 2, 0.87);
	}
}

void	zoom_fractal(t_mlx_data *mlx, int x, int y, float zoom_factor)
{
	double	c_real;
	double	c_imag;
	double	new_width;
	double	new_height;

	c_real = mlx->min_real + x * ((mlx->max_real - mlx->min_real) / 580);
	c_imag = mlx->max_imag - y * ((mlx->max_imag - mlx->min_imag) / 580);
	new_width = (mlx->max_real - mlx->min_real) / zoom_factor;
	new_height = (mlx->max_imag - mlx->min_imag) / zoom_factor;
	mlx->min_real = c_real - new_width / 2;
	mlx->max_real = c_real + new_width / 2;
	mlx->min_imag = c_imag - new_height / 2;
	mlx->max_imag = c_imag + new_height / 2;
}
