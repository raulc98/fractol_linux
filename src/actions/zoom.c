/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:58:56 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 19:50:40 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

static void	zoom_fractal(t_mlx_data *mlx, float zoom_factor);

void	zoom(t_mlx_data *mlx)
{
	mlx->zoom += 1;
	mlx->step /= 1.12; //TODO: este zoom aporta algo¿¿?¿?
	zoom_fractal(mlx, 1.0 / 0.87);
}

void	zoom_out(t_mlx_data *mlx)
{
	mlx->zoom -= 1;
	mlx->step *= 1.12;
	zoom_fractal(mlx, 0.87);
}

static void zoom_fractal(t_mlx_data *mlx, float zoom_factor)
{
	double	c_real;
	double	c_imag;
	double	new_size;

	c_real = mlx->min_real + 290 * ((mlx->max_real - mlx->min_real) / 580);
	printf("c_real: %f\n",c_real);
	c_imag = mlx->max_imag - 290 * ((mlx->max_imag - mlx->min_imag) / 580);
	printf("c_imag: %f\n",c_imag);
	new_size = (mlx->max_imag - mlx->min_imag) / zoom_factor; //Esta operacion que aporta exactamente?¿???¿?
	printf("new_size: %f\n", new_size);
	if(new_size > 0.000001 && new_size < 10)
	{
		mlx->min_real = c_real - new_size / 2;
		mlx->max_real = c_real + new_size / 2;
		mlx->min_imag = c_imag - new_size / 2;
		mlx->max_imag = c_imag + new_size / 2;
	}else{
		printf("Demasiado zoooom :( %f\n", new_size);
	}
}
