/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:28:03 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 19:48:06 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

static int	color_iterations(t_mlx_data *mlx, int iteration);

/*
	COLOR_SCHEME 1,2,3,4: VARIOUS COLORS
	COLOR_SCHEME 5: DEFAULT
*/
int	get_color(t_mlx_data *mlx, int color_scheme, int iteration)
{
	unsigned char	color;
	unsigned char	color_1;
	unsigned char	color_2;
	unsigned char	color_3;

	color = color_iterations(mlx, iteration);
	color_1 = (iteration * 5) % 256;
	color_2 = (iteration * 10) % 256;
	color_3 = (iteration * 15) % 256;
	if (color_scheme == 1)
		return (color_3 << 16 | color_2 << 8 | color_1);
	else if (color_scheme == 2)
		return (color_1 << 16 | color_3 << 8 | color_2);
	else if (color_scheme == 3)
		return (color_2 << 16 | color_1 << 8 | color_3);
	else if (color_scheme == 4)
		return (color_1 << 16 | color_2 << 8 | color_3);
	else
		return (color);
}

int	change_color_scheme(t_mlx_data *mlx, int new_color_scheme)
{
	mlx->color = new_color_scheme;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
	return (1);
}

static int	color_iterations(t_mlx_data *mlx, int iteration)
{
	if (iteration == mlx->max_iterations)
		return (0);
	else
		return ((iteration * 5) % 256);
}
