/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 19:40:24 by rcabrero          #+#    #+#             */
/*   Updated: 2024-06-12 19:40:24 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	calculate_y(t_mlx_data *mlx, int first_time)
{
	#define IMAG_FACTOR (mlx->max_imag - mlx->min_imag) / 720;
	float	c_imag;
	int		y;

	y = 0;
	while (y < 580)
	{
		c_imag = mlx->max_imag - y * IMAG_FACTOR;
		calculate_x(mlx, y, c_imag);
		y++;
	}
	if (first_time)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.ptr, 0, 0);
}

//TODO: NO SE COMO DE CORRECTO ES HACER QUE SEA CONSTANTE.... O SI SE DEFINEN ASI LAS CONSTANTES!!!
void	calculate_x(t_mlx_data *mlx, int y,const float c_imag)
{
	#define		REAL_FACTOR (mlx->max_real - mlx->min_real) / 720;
	t_complex	c;
	float		c_real;
	int			iter;
	int			x;

	x = 0;
	while (x < 580)
	{
		c_real = mlx->min_real + x * REAL_FACTOR;
		c.real = c_real;
		c.imag = c_imag;
		if(mlx->fractal_type)
			iter = iterator_julia(c, mlx->max_iterations, mlx->c_real, mlx->c_imag);
		else
			iter = iterator_mandelbrot(c, mlx->max_iterations);
		put_pixel_to_image(&mlx->img, x, y, get_color(mlx, mlx->color, iter));
		x++;
	}
}

//Itera nuestro fractal y tal....
//ESTE METODO CAMBIA PARA CADA
int	iterator_mandelbrot(t_complex c, int max_iterations)
{
	float	z_real;
	float	z_imag;
	float	temp;
	int		n;

	z_real = 0.0f;
	z_imag = 0.0f;
	temp = 0;
	n = 0;
	while (z_real * z_real + z_imag * z_imag <= 4.0f &&  n < max_iterations)
	{
		temp = z_real;
		z_real = z_real * z_real - z_imag * z_imag + c.real;
		z_imag = 2.0f * temp * z_imag + c.imag;
		n++;
	}
	return (n);
}

int iterator_julia(t_complex z, int max_iterations, float c_real, float c_imag)
{
    float z_real;
    float z_imag;
    float temp;
    int n;

    z_real = z.real;
    z_imag = z.imag;
    n = 0;
    temp = 0;
    while (z_real * z_real + z_imag * z_imag <= 4.0f && n < max_iterations)
    {
        temp = z_real;
        z_real = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = 2.0f * temp * z_imag + c_imag;
        n++;
    }
    return (n);
}

//TODO: SACAR A OTRO SITIO...
//TODO: ESTO QUE HACE EXACTAMENTE¿¿?¿
void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	unsigned int	*pixel_ptr;

	pixel_ptr = (unsigned int *)(image->addr
			+ (y * image->line_length) + (x * (image->bpp / 8)));
	*pixel_ptr = color;
}
