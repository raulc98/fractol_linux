/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:12:35 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 20:40:56 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	initialize_complex(t_mlx_data *mlx, char **argv)
{
	float	c_real;
	float	c_imag;

	c_real = 0;
	c_imag = 0;
	if (mlx->fractal_type == 1)
	{
		if(is_validated_number(argv[2]) || is_validated_number(argv[3]))
		{
			return (-1);
		}
		c_real = ft_atof(argv[2]);
		c_imag = ft_atof(argv[3]);
		if (c_real != -1 && c_imag != -1)
		{
			mlx->c_real = c_real;
			mlx->c_imag = c_imag;
			return (0);
		}
		else
			return (-1);
	}
	else if (mlx->fractal_type == 0)
		return (0);
	return (-1);
}

int initialize_fractol(t_mlx_data *mlx, int type, char **argv)
{
	initialize_mlx_struct(mlx, type);
	if (initialize_complex(mlx, argv) == -1)
		return (-1);
	return (0);
}

/*
	Hay varios ifs que se podrian unificar
	Quizá se debería cambiar el uso de mls_get_data_addr ya que tiene una recomendacion de uso
	Hay que aprenderse bien el metodo y saber que hacen los métodos a los que llama
*/
int	initialize_mlx(t_mlx_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (-1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 580, 580, "fract_ol");
	if (!mlx->win_ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		return (-1);
	}
	mlx->img.ptr = mlx_new_image(mlx->mlx_ptr, 580, 580);
	if (!mlx->img.ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		return (-1);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr,
			&mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
	if (!mlx->img.addr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		return (-1);
	}
	return (0);
}

void	initialize_mlx_struct(t_mlx_data *mlx, int type)
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
