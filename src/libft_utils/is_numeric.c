/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:11:24 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 21:16:26 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	is_numeric(const char *str)
{
	if (str == NULL || *str == '\0')
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '.' && *str != '+' && *str != '-')
		{
			return (-1);
		}
		str++;
	}
	return (0);
}
