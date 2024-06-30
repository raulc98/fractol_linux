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
