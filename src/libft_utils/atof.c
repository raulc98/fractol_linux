/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:09:33 by rcabrero          #+#    #+#             */
/*   Updated: 2024/03/25 20:29:18 by rcabrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

float	extract_sign(const char **str);
float	extract_fraction(const char **str, float sign);
float	extract_integer(const char **str);

float	ft_atof(const char *str)
{
	float	sign;
	float	integer_part;
	float	fraction_part;

	sign = extract_sign(&str);
	integer_part = extract_integer(&str);
	fraction_part = extract_fraction(&str, sign);
	return (integer_part + fraction_part);
}

float	extract_sign(const char **str)
{
	float	sign;

	sign = 1.0;
	if (**str == '-')
	{
		sign = -1.0;
		++(*str);
	}
	else if (**str == '+')
		++(*str);
	return (sign);
}

float	extract_integer(const char **str)
{
	float	value;

	value = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		value = (value * 10.0) + (**str - '0');
		++(*str);
	}
	return (value);
}

float	extract_fraction(const char **str, float sign)
{
	float	value;
	float	factor;

	value = 0.0;
	factor = 1.0;
	if (**str == '.')
	{
		++(*str);
		while (**str >= '0' && **str <= '9')
		{
			factor *= 0.1;
			value += (**str - '0') * factor;
			++(*str);
		}
	}
	return (value * sign);
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
				return (0);
			decimal_point = 1;
		}
		else if (!ft_isdigit((unsigned char)*str))
			return (0);
		++str;
	}
	return (1);
}
