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

#define MAX_ABS_VALUE 10.0
#define FLOAT_OVERFLOW_ERROR -1.0

float ft_atof(const char *str)
{
    float sign;
    float integer_part;
    float fraction_part;

    sign = extract_sign(&str);
    integer_part = extract_integer(&str);
    fraction_part = extract_fraction(&str, sign);

    // Verificar si el resultado excede la capacidad de un float
    if (is_overflow(integer_part, fraction_part))
        return FLOAT_OVERFLOW_ERROR; // Valor de error

    // Verificar si el resultado está fuera del rango [-10, 10]
    double result = integer_part + fraction_part;
    if (result > MAX_ABS_VALUE || result < -MAX_ABS_VALUE)
        return FLOAT_OVERFLOW_ERROR; // Valor de error

    return result;
}

int is_overflow(float integer_part, float fraction_part)
{
	#define CUSTOM_FLT_MAX 3.40282347e+38f
	#define CUSTOM_FLT_MIN 1.17549435e-38f

    // Verificar si la suma de integer_part y fraction_part produce un valor de overflow
    if (integer_part > 0 && integer_part > (CUSTOM_FLT_MAX - fraction_part))
        return 1;
    if (integer_part < 0 && integer_part < (CUSTOM_FLT_MIN - fraction_part))
        return 1;
    return 0;
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

