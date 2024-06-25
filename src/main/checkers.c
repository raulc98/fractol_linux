/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-25 19:24:31 by rcabrero          #+#    #+#             */
/*   Updated: 2024-06-25 19:24:31 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

/*
	check fractol type, mandelbrot return 0,
	julia return 1
	and error return -1
*/
int check_fractol_type(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		return (0);
	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
		return (1);
	else
		return (-1);
}

/*
	TODO: LO MISMO SE PUEDE CAMBIAR POR UN MENSAJE DE ERROR MAS ADECUADO
*/
int check_args_julia(t_mlx_data *mlx, char **argv)
{
	float c_real;
	float c_imag;

	if (is_numeric(argv[2]) == -1)
		return (-1);
	if (is_numeric(argv[3]) == -1)
		return (-1);
	c_real = ft_atof(argv[2]);
	if (c_real == -1)
	{
		parameters_instructions();
		cleanup_mlx(mlx);
		return (-1);
	}
	printf("Atof...");
	c_imag = ft_atof(argv[3]);
	if (c_imag == -1)
	{
		parameters_instructions();
		cleanup_mlx(mlx);
		return (-1);
	}
	printf("C_REAL %f\n",c_real);
	mlx->c_real = c_real;
	printf("C_IMAG %f\n",c_imag);
	mlx->c_imag = c_imag;
	return (1);
}