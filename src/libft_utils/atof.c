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
int		is_overflow(float integer_part, float fraction_part);

float	ft_atof(const char *str)
{
	float	integer_part;
	float	fraction_part;
	float	max_abs_value;
	float	overflow_error;
	float	result;

	max_abs_value = 10.0;
	overflow_error = -1.0;
	integer_part = extract_integer(&str);
	fraction_part = extract_fraction(&str, extract_sign(&str));
	if (is_overflow(integer_part, fraction_part))
		return (overflow_error);
	result = integer_part + fraction_part;
	if (result > max_abs_value || result < -max_abs_value)
		return (overflow_error);
	return (result);
}

int	is_overflow(float integer_part, float fraction_part)
{
	float	custom_flt_max;
	float	custom_flt_min;

	custom_flt_max = 3.40282347e+38f;
	custom_flt_min = 1.17549435e-38f;
	if (integer_part > 0 && integer_part > (custom_flt_max - fraction_part))
		return (1);
	if (integer_part < 0 && integer_part < (custom_flt_min - fraction_part))
		return (1);
	return (0);
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
