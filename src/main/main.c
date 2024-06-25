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

/*
	Julia Examples Values
	c_real = -0.7;
	c_imag = 0.28015
	----------------------
	c_real = 0.285;
	float c_imag = -0.01;
	----------------------
*/
// atexit(leaks);
// Comprobamos que argumento nos llega
// Comprobamos si es julia si tiene todos los argumentos que necesitamos
int main(int argc, char **argv)
{
	int type;

	type = check_fractol_type(argc, argv);
	if (type == -1)
		parameters_instructions();
	fractol_controller(type, argv);
	return (0);
}