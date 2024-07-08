/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:20:50 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 19:48:07 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	increase_iterations(t_mlx_data *mlx)
{
	if (mlx->max_iterations < 150)
		mlx->max_iterations += 10;
	return (1);
}

int	decrease_iterations(t_mlx_data *mlx)
{
	if (mlx->max_iterations > 40)
		mlx->max_iterations -= 10;
	return (1);
}
