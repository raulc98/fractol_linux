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

int	close_window(t_mlx_data *mlx)
{
	mlx_destroy_image (mlx->mlx_ptr, mlx->img.ptr);
	mlx_destroy_window (mlx->mlx_ptr, mlx->win_ptr);
	free (mlx);
	exit (0);
}

//TODO: SE PUEDE MEJORAR
/*
	Hay varios ifs que se podrian unificar
	Quizá se debería cambiar el uso de mls_get_data_addr ya que tiene una recomendacion de uso
	Hay que aprenderse bien el metodo y saber que hacen los métodos a los que llama
*/
int	initialize_mlx(t_mlx_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 580, 580, "fract_ol");
	if (!mlx->win_ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		return (1);
	}
	mlx->img.ptr = mlx_new_image(mlx->mlx_ptr, 580, 580);
	if (!mlx->img.ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		return (1);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr,
			&mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
	if (!mlx->img.addr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		return (1);
	}
	return (0);
}

//TODO: REPASAR PARA QUE QUIERO EL TYPE
void	init_struct(t_mlx_data *mlx, int type)
{
	mlx->zoom = 0;
	mlx->move_x = -0.5;
	mlx->move_y = 0;
	mlx->step = 0.1;
	mlx->min_real = -2.0;
	mlx->max_real = 1.0;
	mlx->min_imag = -1.5;
	mlx->max_imag = 1.5;
	mlx->max_iterations = 40;
	mlx->fractal_type = type;
	mlx->color = 1;
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
