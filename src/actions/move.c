/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:01:21 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 19:48:07 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

void	move_up(t_mlx_data *mlx, float step)
{
	mlx->min_imag -= step;
	mlx->max_imag -= step;
}

void	move_down(t_mlx_data *mlx, float step)
{
	mlx->min_imag += step;
	mlx->max_imag += step;
}

void	move_rigth(t_mlx_data *mlx, float step)
{
	mlx->min_real -= step;
	mlx->max_real -= step;
}

void	move_left(t_mlx_data *mlx, float step)
{
	mlx->min_real += step;
	mlx->max_real += step;
}
