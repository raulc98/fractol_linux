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
//TODO: DEBERIAMOS DE CAMBIARLOS POR QUE LA GENTE DICE QUE ESTA AK REVES... FALSO!
int	key_press(int keycode, t_mlx_data *mlx)
{
	printf("Has pulsado la tecla: %d\n",keycode);
	if (keycode == 65363 || keycode == 100)
		move_rigth(mlx, mlx->step);
	else if (keycode == 65361 || keycode == 97)
		move_left(mlx, mlx->step);
	else if (keycode == 65364 || keycode == 115)
		move_down(mlx, mlx->step);
	else if (keycode == 65362 || keycode == 119)
		move_up(mlx, mlx->step);
	else if (keycode == 65451 || keycode == 43)
		zoom(mlx);
	else if (keycode == 65453 || keycode == 231)
		zoom_out(mlx);
	else if (keycode == 49)
		increase_iterations(mlx);
	else if (keycode == 50)
		decrease_iterations(mlx);
	else
		handle_options_input(keycode, mlx);
	calculate_y(mlx,-1);
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
int	handle_options_input(int keycode, t_mlx_data *data)
{
	if (keycode == 65307)
	{
		free(data->mlx_ptr);
		exit(1);
	}
	if (keycode == 15)
		change_color_scheme(data, 1);
	else if (keycode == 51)
		change_color_scheme(data, 2);
	else if (keycode == 52)
		change_color_scheme(data, 3);
	else if (keycode == 53)
		change_color_scheme(data, 4);
	return (0);
}

static void	change_color_scheme(t_mlx_data *mlx, int new_color_scheme)
{
	mlx->color = new_color_scheme;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}
