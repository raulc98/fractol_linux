/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:12:35 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 20:40:56 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"
#include <unistd.h>

int	init_complex(t_mlx_data *mlx, char **argv)
{
	float	c_real;
	float	c_imag;

	c_real = 0;
	c_imag = 0;
	printf("\n\n mlx->fractal_type %d\n\n",mlx->fractal_type);
	if (mlx->fractal_type == 1)
	{
		printf("ES JUUUUUUUUUULIA \n\n");
		c_real = ft_atof(argv[2]);
		c_imag = ft_atof(argv[3]);
		if (c_real != -1 && c_imag != -1)
		{
			mlx->c_real = c_real;
			mlx->c_imag = c_imag;
			return (0);
		}
		else
			return (1);
	}
	else if (mlx->fractal_type == 0)
		return (0);
	return (1);
}
