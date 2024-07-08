/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:12:13 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 20:23:44 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (-1);
}

int	is_validated_number(const char *str)
{
	int	decimal_point;

	if (*str == '\0' || (str[1] == '\0' && (*str == '+' || *str == '-')))
		return (0);
	if (*str == '+' || *str == '-')
		++str;
	decimal_point = 0;
	while (*str)
	{
		if (*str == '.')
		{
			if (decimal_point)
				return (-1);
			decimal_point = 1;
		}
		else if (!ft_isdigit((unsigned char)*str))
			return (-1);
		++str;
	}
	return (1);
}
