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
	COLOR_SCHEME 1: GREEN
	COLOR_SCHEME 2: RED
	COLOR_SCHEME 3: BLUE
	COLOR_SCHEME 4: VARIOUS COLORS
	COLOR_SCHEME 5: DEFAULT
*/
int	get_color(t_mlx_data *mlx, int color_scheme, int iteration)
{
	// unsigned char	color;
	// unsigned char	red;
	// unsigned char	green;
	// unsigned char	blue;

	unsigned char color = color_iterations(mlx, iteration);
	printf("COLOR: %d\n",color);
	printf("COLOR_SCHEME: %d\n", color_scheme);
	// if (color_scheme == 1)
	// {
	// 	printf("PASA POR AQUI");
		return (color << 8);
	// }
	// else if (color_scheme == 2)
	// 	return (color << 16);
	// else if (color_scheme == 3)
	// 	return (color);
	// else if (color_scheme == 4)
	// {
	// 	red = (iteration * 5) % 256;
	// 	green = (iteration * 10) % 256;
	// 	blue = (iteration * 15) % 256;
	// 	return (red << 16 | green << 8 | blue);
	// }
	// else
	// {
	// 	printf("PASAMOS POR AAQUIIII");
	// 	return (color << 16 | 33 << 8 | 33);
	// }
}

static int	color_iterations(t_mlx_data *mlx, int iteration)
{
	if (iteration == mlx->max_iterations)
		return (0);
	else
		return ((iteration * 5) % 256);
}
