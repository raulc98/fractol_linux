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
	int is_action;

	is_action = 0;
	if (keycode == 65363 || keycode == 100)
		is_action = move_rigth(mlx, mlx->step);
	else if (keycode == 65361 || keycode == 97)
		is_action = move_left(mlx, mlx->step);
	else if (keycode == 65364 || keycode == 115)
		is_action = move_down(mlx, mlx->step);
	else if (keycode == 65362 || keycode == 119)
		is_action = move_up(mlx, mlx->step);
	else if (keycode == 65451 || keycode == 43)
		is_action = zoom(mlx);
	else if (keycode == 65453 || keycode == 231)
		is_action = zoom_out(mlx);
	else if (keycode == 49)
		is_action = increase_iterations(mlx);
	else if (keycode == 50)
		is_action = decrease_iterations(mlx);
	else
		is_action = handle_options_input(keycode, mlx);
	if (is_action == 1)
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
	int	is_action;

	is_action = 0;
	if (keycode == 65307)
	{
		free(data->mlx_ptr);
		exit(1);
	}
	if (keycode == 51)
		is_action = change_color_scheme(data, 2);
	else if (keycode == 52)
		is_action = change_color_scheme(data, 3);
	else if (keycode == 53)
		is_action = change_color_scheme(data, 4);
	else if (keycode == 54)
		is_action = change_color_scheme(data, 1);
	return (is_action);
}
