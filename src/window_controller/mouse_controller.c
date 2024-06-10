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
	printf("BOTOOOON: %d\n",button);
	(void)x;
	(void)y;
	if (button == 4)
		zoom(mlx);
	else if (button == 5)
		zoom_out(mlx);
	return (0);
}
