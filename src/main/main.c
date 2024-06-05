/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:40:20 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 21:36:53 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

static int check_fractol_type(int argc, char **argv);
static int check_args_julia(t_mlx_data *mlx, char **argv);
static int create_fractol(t_mlx_data *mlx, int type, char **argv);
static int init_fractol(int type, char **argv);

// Comprobamos que argumento nos llega
// Comprobamos si es julia si tiene todos los argumentos que necesitamos
int main(int argc, char **argv)
{
	int type;
	// Controlamos parametros
	type = check_fractol_type(argc, argv);
	if (type == -1)
		parameters_instructions();
	// Si type es 0, mandelbrot, si es 1 julia
	init_fractol(type, argv);
	// Si no, hacemos las comprobaciones pertinentes por tipo de fractol!
	return (0);
}

/*
	check fractol type, mandelbrot return 0,
	julia return 1
	and error return -1
*/
static int check_fractol_type(int argc, char **argv)
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
static int check_args_julia(t_mlx_data *mlx, char **argv)
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
	c_imag = ft_atof(argv[3]);
	if (c_imag == -1)
	{
		parameters_instructions();
		cleanup_mlx(mlx);
		return (-1);
	}
	mlx->c_real = c_real;
	mlx->c_imag = c_imag;
	return (0);
}

// TODO: ESte metodo hay que rehacerlo entero!
static int init_fractol(int type, char **argv)
{
	t_mlx_data *mlx;

	// TODO: ESTO ES MUY MEJORABLE..............................
	mlx = NULL;
	mlx = malloc(sizeof(t_mlx_data));
	printf("Hasta aqui bien");
	if (mlx == NULL)
	{
		free(mlx);
		return (-1);
	}
	// declaramos checkeo de si es julia para hacer el check args...
	// TODO: PROBABLEMENTE HAYA QUE LIBERAR MEMORIA EN LOS ERRORES....
	if (create_fractol(mlx, type, argv) == -1)
	{
		printf("Ha fallado?!!");
		return (-1);
	}
	printf("type %d...", type);
	if (type == 0)
	{
		printf("DRAW_MANDELBROT...");
		draw_mandelbrot(mlx, 1);
	}
	else if (type == 1) // TODO: LO MISMO SE PUEDE ARREGLAR ESTA LINEA....
	{
		printf("JULIA");
		if (check_args_julia(mlx, argv))
			draw_julia(mlx, 1);
		else
			return (-1);
	}
	if (mlx != NULL && mlx->mlx_ptr != NULL)
	{
		printf("Pasamos por aqui");
		set_hooks(mlx);
		mlx_loop(mlx->mlx_ptr);
		cleanup_mlx(mlx);
		return (0);
	}
	else
	{
		return (-1);
	}
}

/**
 * Crea el el complejo y inicia la estructura....
 */
static int create_fractol(t_mlx_data *mlx, int type, char **argv)
{
	if (init_complex(mlx, argv) == -1)
	{
		parameters_instructions();
		cleanup_mlx(mlx);
		return (-1);
	}
	init_struct(mlx, type);
	return (0);
}
