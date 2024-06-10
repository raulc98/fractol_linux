/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:01:21 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 19:48:07 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void check_fractol_type_controller(t_mlx_data *mlx)
{
	if (mlx->fractal_type == 0)
		draw_mandelbrot(mlx, -1);
	else
		draw_julia(mlx, -1);
}