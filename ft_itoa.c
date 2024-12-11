/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:35:29 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 03:57:30 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countdigits(long number_unsigned_casted, int sign);
static void		proc_int(long from_i, char *to_a, size_t digits, int sign);

//14L
/**
 * @brief 
 * 
 * @param from_integer 
 * @return char* 
 */
char	*ft_itoa(int from_integer)
{
	char	*to_ascii;
	int		sign;
	long	num_uc;
	size_t	digits;

	sign = POSITIVE;
	if (from_integer < 0)
		sign = NEGATIVE;
	num_uc = (long)from_integer * sign;
	digits = count_digits(num_uc, sign);
	to_ascii = (char *)ft_calloc((digits + 1), sizeof(char));
	if (to_ascii != NULL)
		proc_int(num_uc, to_ascii, digits, sign);
	return (to_ascii);
}

//13L
/**
 * @brief 
 * 
 * @param num_uc 
 * @param sign 
 * @return size_t 
 */
static size_t	count_digits(long num_uc, int sign)
{
	size_t	digits;

	digits = 0;
	if (num_uc == 0)
		return (1);
	else if (sign == NEGATIVE)
		digits += 1;
	while (num_uc > 0)
	{
		num_uc /= 10;
		digits += 1;
	}
	return (digits);
}

//8L
/**
 * @brief 
 * 
 * @param from_i 
 * @param to_a 
 * @param digits 
 * @param sign 
 */
static void	proc_int(long from_i, char *to_a, size_t digits, int sign)
{
	while (digits > 0)
	{
		digits -= 1;
		to_a[digits] = from_i % 10 + '0';
		from_i /= 10;
	}
	if (sign == NEGATIVE)
		to_a[0] = '-';
}
