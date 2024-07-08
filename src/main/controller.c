/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:32:36 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 19:48:06 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	fractol_controller(int type, char **argv)
{
	t_mlx_data	*mlx;

	mlx = NULL;
	mlx = malloc(sizeof(t_mlx_data));
	if (mlx == NULL || initialize_mlx(mlx) == -1
		|| initialize_fractol(mlx, type, argv) == -1)
	{
		parameters_instructions();
		free(mlx);
		return (-1);
	}
	handle_fractol(mlx);
	return (0);
}

void	handle_fractol(t_mlx_data *mlx)
{
	calculate_y(mlx, 1);
	set_hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	cleanup_mlx(mlx);
}

int	close_window(t_mlx_data *mlx)
{
	mlx_destroy_image (mlx->mlx_ptr, mlx->img.ptr);
	mlx_destroy_window (mlx->mlx_ptr, mlx->win_ptr);
	free (mlx);
	exit (0);
}

void	set_hooks(t_mlx_data *mlx)
{
	mlx_key_hook(mlx->win_ptr, key_press, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_press, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, mlx);
}

void	cleanup_mlx(t_mlx_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free (mlx);
}
