/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:24:35 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 19:48:07 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	parameters_instructions(void)
{
	ft_putstr_fd("ERROR: You must enter valid parameters.\n", 1);
	ft_putstr_fd("-----------------MANUAL------------------\n", 1);
	ft_putstr_fd("|  For Mandelbrot: ./fractol mandelbrot |\n", 1);
	ft_putstr_fd("|  For Julia: ./fractol julia           |\n", 1);
	ft_putstr_fd("-----------------------------------------\n", 1);
	ft_putstr_fd("Veeeery easy, come on...\n", 1);
	ft_putstr_fd("---------------MOOOVEMENT----------------\n", 1);
	ft_putstr_fd("RIGHT: D OR RIGHT KEY\n", 1);
	ft_putstr_fd("LEFT: A OR LEFT KEY\n", 1);
	ft_putstr_fd("UP: W OR UP KEY\n", 1);
	ft_putstr_fd("DOWN: A OR DOWN KEY\n", 1);
	ft_putstr_fd("-----------------ZOOM--------------------\n", 1);
	ft_putstr_fd("ZOOM IN: + OR MOUSE\n", 1);
	ft_putstr_fd("ZOOM OUT: - OR MOUSE\n", 1);
	ft_putstr_fd("---------------ITERATIONS----------------\n", 1);
	ft_putstr_fd("INCREASE: 1 OR \n", 1);
	ft_putstr_fd("DECREASE: 2 OR \n", 1);
	ft_putstr_fd("-----------------COLOR-------------------\n", 1);
	ft_putstr_fd("COLOR_SCHEMES : R,T,Y OR U\n", 1);
	ft_putstr_fd("-----------------------------------------\n", 1);
}
