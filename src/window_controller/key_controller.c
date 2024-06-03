/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:02:11 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 21:06:52 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

static void	change_color_scheme(t_mlx_data *mlx, int new_color_scheme);

/**
 * -------KEY MANUAL--------
 * D OR -> 		: RIGHT
 * A OR <- 		: LEFT
 * S OR DOWN	: DOWN
 * W OR UP 		: UP
 * ZOOM 		: +
 * ZOOM OUT 	: -
 * ITERATIONS + : 1
 * IRERATIONS - : 2
*/
int	key_press(int keycode, t_mlx_data *mlx)
{
	if (keycode == 2 || keycode == 124)
		move_rigth(mlx, mlx->step);
	else if (keycode == 0 || keycode == 123)
		move_left(mlx, mlx->step);
	else if (keycode == 1 || keycode == 125)
		move_down(mlx, mlx->step);
	else if (keycode == 13 || keycode == 126)
		move_up(mlx, mlx->step);
	else if (keycode == 69 || keycode == 35 || keycode == 30)
		zoom(mlx);
	else if (keycode == 78 || keycode == 36 || keycode == 42)
		zoom_out(mlx);
	else if (keycode == 19 || keycode == 33)
		increase_iterations(mlx);
	else if (keycode == 18 || keycode == 39)
		decrease_iterations(mlx);
	else
		handle_input (keycode, mlx);
	return (0);
}

/*
	Control keys
	ESC: 53-> Close the program
	R: 15-> Change color to red
	T: 16-> Change color to green
	Y: 27-> Change color to blue
	U: 32-> Change color to many colors
*/
int	handle_input(int keycode, t_mlx_data *data)
{
	if (keycode == 53)
	{
		free(data->mlx_ptr);
		exit(1);
	}
	if (keycode == 15)
		change_color_scheme(data, 1);
	else if (keycode == 16)
		change_color_scheme(data, 2);
	else if (keycode == 17)
		change_color_scheme(data, 3);
	else if (keycode == 32)
		change_color_scheme(data, 4);
	return (0);
}

static void	change_color_scheme(t_mlx_data *mlx, int new_color_scheme)
{
	mlx->color = new_color_scheme;
	if (mlx->fractal_type == 0)
		draw_mandelbrot(mlx, -1);
	else
		draw_julia(mlx, -1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}
