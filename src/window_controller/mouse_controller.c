/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:01:47 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 21:03:04 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	mouse_press(int button, int x, int y, t_mlx_data *mlx)
{
	int is_action;

	(void)x;
	(void)y;
	is_action = 0;
	if (button == 4)
		is_action = zoom(mlx);
	else if (button == 5)
		is_action = zoom_out(mlx);
	if (is_action)
		calculate_y(mlx,-1);
	return (0);
}
