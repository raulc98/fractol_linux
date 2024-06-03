/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:20:50 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 19:48:07 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	increase_iterations(t_mlx_data *mlx)
{
	mlx->max_iterations += 10;
	if (mlx->fractal_type == 0)
		draw_mandelbrot(mlx, -1);
	else
		draw_julia(mlx, -1);
}

void	decrease_iterations(t_mlx_data *mlx)
{
	mlx->max_iterations -= 10;
	if (mlx->fractal_type == 0)
		draw_mandelbrot(mlx, -1);
	else
		draw_julia(mlx, -1);
}
