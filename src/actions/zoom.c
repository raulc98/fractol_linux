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

static void	zoom_fractal(t_mlx_data *mlx, float zoom_factor, int is_zoom);

int	zoom(t_mlx_data *mlx)
{
	if (mlx->zoom <= 110)
	{
		mlx->zoom += 1;
		zoom_fractal(mlx, 1.0 / 0.87, 1);
	}
	return (1);
}

int	zoom_out(t_mlx_data *mlx)
{
	if (mlx->zoom >= -10)
	{
		mlx->zoom -= 1;
		zoom_fractal(mlx, 0.87, 0);
	}
	return (1);
}

static void	zoom_fractal(t_mlx_data *mlx, float zoom_factor, int is_zoom)
{
	float	c_real;
	float	c_imag;
	float	new_size;

	c_real = mlx->min_real + 300 * ((mlx->max_real - mlx->min_real) / 600);
	c_imag = mlx->max_imag - 300 * ((mlx->max_imag - mlx->min_imag) / 600);
	new_size = (mlx->max_imag - mlx->min_imag) / zoom_factor;
	mlx->min_real = c_real - new_size / 2;
	mlx->max_real = c_real + new_size / 2;
	mlx->min_imag = c_imag - new_size / 2;
	mlx->max_imag = c_imag + new_size / 2;
	if (is_zoom)
		mlx->step /= 1.12;
	else
		mlx->step *= 1.12;
}
