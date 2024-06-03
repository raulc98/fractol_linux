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
// static int	check_args_julia(t_mlx_data *mlx, char **argv);
// static int	check_args(int argc, char **argv);
// static int	init_fractol(t_mlx_data *mlx, int type, char **argv);

// atexit(leaks);
// Main va a funcionar de controler, Y NADA MAS
//  int	main(int argc, char **argv)
//  {
//  	t_mlx_data	*mlx; //Declaramos la estructura t_mlx_data
//  	int			type; //El tipo de fractol

// 	mlx = NULL;
// 	type = check_args(argc, argv); //comprobamos los argumentos y devuelve tipo??¿??¿?
// 	mlx = malloc(sizeof(t_mlx_data));
// 	if (type == -1 || mlx == NULL)
// 	{
// 		parameters_instructions();
// 		free (mlx);
// 		return (1);
// 	}
// 	if (initialize_mlx(mlx) == 1)
// 	{
// 		free (mlx);
// 		return (1);
// 	}
// 	if (init_fractol(mlx, type, argv) == -1)
// 	{
// 		parameters_instructions();
// 		cleanup_mlx(mlx);
// 		return (1);
// 	}
// 	return (0);
// }

// Comprobamos que argumento nos llega
// Comprobamos si es julia si tiene todos los argumentos que necesitamos
int main(int argc, char **argv)
{
	int type;
	// Controlamos parametros
	type = check_fractol_type(argc, argv);
	if (type == -1)
		parameters_instructions();
	//Si type es 0, mandelbrot, si es 1 julia
	init_fractol(type,argv);
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

static int	check_args_julia(t_mlx_data *mlx, char **argv)
{
	float	c_real;
	float	c_imag;

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

// //TODO: DEBERIAMOS DE PARTIR ESTE METODO...
// static int	check_args(int argc, char **argv)
// {
// 	int	type;

// 	if (argc < 2)  //Si argumento es menor de 2, esta mal...
// 	{
// 		parameters_instructions();
// 		return (-1);
// 	}
// 	else if (argc == 4) //Si argumento es igual a 4, pregunta si es numerico
// 	{
// 		if (is_numeric(argv[2]) == -1)
// 			return (-1);
// 		if (is_numeric(argv[3]) == -1)
// 			return (-1);
// 	}check_args
// 	type = check_fractol_type(argc, argv);
// 	if (type == 1)
// 		return (type);
// 	else if (type == 0)
// 		return (type);
// 	else
// 	{
// 		return (-1);
// 	}
// }

// TODO: ESte metodo hay que rehacerlo entero!
static int init_fractol(int type, char **argv)
{
	t_mlx_data	*mlx;

	mlx = NULL;
	if(mlx = malloc(sizeof(t_mlx_data)) == NULL)
	{
		free (mlx);
		return (-1);
	}
	//declaramos checkeo de si es julia para hacer el check args...
	//TODO: PROBABLEMENTE HAYA QUE LIBERAR MEMORIA EN LOS ERRORES....
	if(!create_fractol(mlx,type,argv))
		return (-1);
	if(type == 0)
		draw_mandelbrot(mlx, 1);
	else if (type == 1) //TODO: LO MISMO SE PUEDE ARREGLAR ESTA LINEA....
	{
		if(check_args_julia(mlx, argv))
			draw_julia(mlx, 1);
		else
			return (-1);
	}
	set_hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	cleanup_mlx(mlx);
	return (0);
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
