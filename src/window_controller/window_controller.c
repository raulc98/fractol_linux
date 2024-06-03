/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:30:27 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 21:06:40 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	mandelbrot_iterations(t_complex c, int max_iterations)
{
	t_complex	z;
	t_complex	new_z;
	int			iterations;

	z.real = 0;
	z.imag = 0;
	iterations = 0;
	new_z.imag = 0;
	new_z.real = 0;
	while (iterations < max_iterations)
	{
		if ((z.real * z.real) + (z.imag * z.imag) > 4.0)
		{
			break ;
		}
		new_z.real = (z.real * z.real) - (z.imag * z.imag) + c.real;
		new_z.imag = 2 * z.real * z.imag + c.imag;
		z = new_z;
		iterations++;
	}
	return (iterations);
}
