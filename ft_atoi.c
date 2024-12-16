/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:09:58 by yuske             #+#    #+#             */
/*   Updated: 2024/09/07 18:44:08 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define OK 0
#define OVERFLOW (1)
#define UNDERFLOW (-1)
#define POSITIVE (1)
#define NEGATIVE (-1)
#define INVAL_ARG (-1)

// static int	sign_chk(const char *from_ascii, int sign);
static int	_skip_spaces(const char **from_ascii);
static int	_check_sign(const char **from_ascii);
static int	_proc_digits(const char *from_ascii, int sign);
static int	__check_flow(int sign, unsigned long digits2p, char digit1);

//17L
/**
 * @brief Convert a string to an integer
 * @param from_ascii The string to be converted
 * @param to_integer number converted from the string "from_ascii"
 * @param sign indicates whether the number is positive/negative
 * @param flow indicates if the size is within that of "int"
 * @return The converted integer value
 */
// int	ft_atoi(const char *from_ascii)
// {
// 	int				sign;
// 	int				flow;
// 	unsigned long	to_integer;

// 	while (ft_isspace(*from_ascii))
// 		from_ascii += 1;
// 	sign = _check_sign(&from_ascii);
// 	to_integer = 0;
// 	while (ft_isdigit(*from_ascii))
// 	{
// 		flow = _check_flow(sign, to_integer, *from_ascii);
// 		if (flow == OVERFLOW)
// 			return ((int)LONG_MAX);
// 		else if (flow == UNDERFLOW)
// 			return ((int)LONG_MIN);
// 		to_integer = (to_integer * 10) + (*from_ascii - '0');
// 		from_ascii += 1;
// 	}
// 	return ((int)to_integer * sign);
// }

int	ft_atoi(const char *from_ascii)
{
	int	sign;
	int	to_integer;

	_skip_spaces(&from_ascii);
	sign = _check_sign(&from_ascii);
	to_integer = _proc_digits(from_ascii, sign);
	return (to_integer);
}

static int	_skip_spaces(const char **from_ascii)
{
	const char	*head;

	if (!from_ascii || !*from_ascii)
		return (INVAL_ARG);
	head = *from_ascii;
	while (**from_ascii && ft_isspace(**from_ascii))
		(*from_ascii) += 1;
	return (*from_ascii - head);
}

//7L
/**
 * @brief Determine the sign of the number and update the pointer
 * @param from_ascii A pointer to the current position in the string
 * @param sign The current sign of the number
 * @note 'while' loop for Piscine, 'if' for original/libft
 * @return int The updated sign of the number
 */
static int	_check_sign(const char **from_ascii)
{
	int	sign;

	sign = POSITIVE;
	if (**from_ascii == '-' || **from_ascii == '+')
	{
		if (**from_ascii == '-')
			sign *= NEGATIVE;
		(*from_ascii) += 1;
	}
	return (sign);
}
		// (*from_ascii)++;

// static int	_check_sign(const char *from_ascii, int sign)
// {
// 	sign = POSITIVE;
// 	if (*from_ascii == '-' || *from_ascii == '+')
// 	{
// 		if (*from_ascii == '-')
// 			sign *= NEGATIVE;
// 		from_ascii += 1;
// 	}
// 	return (sign);
// }


static int _proc_digits(const char *from_ascii, int sign)
{
	unsigned long to_integer;
	int flow;

	to_integer = 0;
	while (ft_isdigit(*from_ascii))
	{
		flow = __check_flow(sign, to_integer, *from_ascii);
		if (flow == OVERFLOW)
			return ((int)LONG_MAX);
		else if (flow == UNDERFLOW)
			return ((int)LONG_MIN);
		to_integer = (to_integer * 10) + (*from_ascii - '0');
		from_ascii += 1;
	}
	return ((int)(to_integer * sign));
}

//7L
/**
 * @brief Check for overflow and underflow
 * @param sign The current sign of the number
 * @param figure2p The current integer value being computed
 * @param figure1 The current digit being processed
 * @return An integer indicating 
 * 		if the operation resulted in overflow, underflow, or success
 */
static int	__check_flow(int sign, unsigned long digits2p, char digit1)
{
	if (sign == POSITIVE\
		&& (digits2p > (unsigned long)(LONG_MAX - (digit1 - '0')) / 10))
		return (OVERFLOW);
	else if (sign == NEGATIVE\
		&& (digits2p > (unsigned long)(-(LONG_MIN + (digit1 - '0'))) / 10)
		return (UNDERFLOW);
	return (OK);
}

//19L
// static int	_check_flow(int sign, unsigned long figure2p, char figure1)
// {
// 	if (sign == POSITIVE)
// 	{
// 		if (figure2p == LONG_MAX / 10 && figure1 - '0' >= LONG_MAX % 10)
// 			return (OVERFLOW);
// 		else if (figure2p > LONG_MAX / 10)
// 			return (OVERFLOW);
// 	}
// 	else if (sign == NEGATIVE)
// 	{
// 		if (figure2p == LONG_MAX / 10
// 			&& (unsigned long)(figure1 - '0') >= (unsigned long)LONG_MIN % 10)
// 			return (UNDERFLOW);
// 		else if (figure2p > LONG_MAX / 10)
// 			return (UNDERFLOW);
// 	}
// 	return (OK);
// }

//2. 14L no long checker
// int	ft_atoi(const char *from_ascii)
// {
// 	long	to_integer;
// 	int		sign;

// 	to_integer = 0;
// 	while ((*from_ascii >= '\t' && *from_ascii <= '\r') || *from_ascii == ' ')
// 		from_ascii++;
// 	sign = POSITIVE;
// 	if (*from_ascii == '-')
// 		sign = NEGATIVE;
// 	if (*from_ascii == '-' || *from_ascii == '+')
// 		from_ascii++;
// 	while (*from_ascii >= '0' && *from_ascii <= '9')
// 		to_integer = (to_integer * 10) + (*from_ascii++ - '0');
// 	return ((int)to_integer * sign);
// }

#include <stdio.h>
#include <stdlib.h>

const char *inputs[] = {
    "+-0",
    "+-42",
    "+---+42",
    "+---+--42",
    "+---+---42",
    "     \n+---+---42",
    "     \n+---+--42",
    "     \t\n\f\v\r+---+--42",
    "     \t\n\f\v\r-42",
    "     \t\n\f\v\r--42",
    "     \t\n\f\v\r---42",
    "     \t\n\f\v\r----42",
    "     \t\n\f\v\r-----42",
    " 2147483647paper",
    " 2147483650",
    " 32147483650",
    " -2147483648paper",
    " -2147483650",
    " -322147483650",
    " -21474~=83650",
    " - 21474~=83650",
    " 9223372036854775807",
    " -9223372036854775808",
    " 9223372036854775806",
    " -9223372036854775807",
    " 922337203685477580610",
    " -9223372036854775810",
	"000123", "-000123", "abc", "+-+", "",
    NULL // Sentinel to indicate end of the array
};

void test_and_print_atoi(const char **inputs)
{
    for (int i = 0; inputs[i] != NULL; i++) // Loop through input strings
    {
        printf("    input: \"%s\"\n", inputs[i]);
	printf("   atoi(): %d\n", atoi(inputs[i]));
	printf("ft_atoi(): %d\n", ft_atoi(inputs[i]));
    }
}

int main(void)
{
    test_and_print_atoi(inputs);
    return 0;
}

// int	main(void)
// {
// 	// printf("\n\t[null]\n");
// 	// printf("          +-0: %d\n", atoi(NULL));//segv
// 	// printf("          +-0: %d\n", ft_atoi(NULL));//segv
// 	printf("\n\t[sign space]\n");
// 	printf("          +-0: %d\n", atoi("+-0"));
// 	printf("          +-0: %d\n", ft_atoi("+-0"));
// 	printf("         +-42: %d\n", atoi("+-42"));
// 	printf("         +-42: %d\n", ft_atoi("+-42"));
// 	printf("      +---+42: %d\n", atoi("+---+42"));
// 	printf("      +---+42: %d\n", ft_atoi("+---+42"));
// 	printf("    +---+--42: %d\n", atoi("+---+--42"));
// 	printf("    +---+--42: %d\n", ft_atoi("+---+--42"));
// 	printf("   +---+---42: %d\n", atoi("+---+---42"));
// 	printf("   +---+---42: %d\n", ft_atoi("+---+---42"));
// 	printf("SP +---+---42: %d\n", atoi("     \n+---+---42"));
// 	printf("SP +---+---42: %d\n", ft_atoi("     \n+---+---42"));
// 	printf("SP  +---+--42: %d\n", atoi("     \n+---+--42"));
// 	printf("SP  +---+--42: %d\n", ft_atoi("     \n+---+--42"));
// 	printf("SP  +---+--42: %d\n", atoi("     \t\n\f\v\r+---+--42"));
// 	printf("SP  +---+--42: %d\n", ft_atoi("     \t\n\f\v\r+---+--42"));
// 	printf("SP        -42: %d\n", atoi("     \t\n\f\v\r-42"));
// 	printf("SP        -42: %d\n", ft_atoi("     \t\n\f\v\r-42"));
// 	printf("SP       --42: %d\n", atoi("     \t\n\f\v\r--42"));
// 	printf("SP       --42: %d\n", ft_atoi("     \t\n\f\v\r--42"));
// 	printf("SP      ---42: %d\n", atoi("     \t\n\f\v\r---42"));
// 	printf("SP      ---42: %d\n", ft_atoi("     \t\n\f\v\r---42"));
// 	printf("SP     ----42: %d\n", atoi("     \t\n\f\v\r----42"));
// 	printf("SP     ----42: %d\n", ft_atoi("     \t\n\f\v\r----42"));
// 	printf("SP    -----42: %d\n", atoi("     \t\n\f\v\r-----42"));
// 	printf("SP    -----42: %d\n", ft_atoi("     \t\n\f\v\r-----42"));
// 	printf("\n\t[IMAX IMIN]\n");
// 	printf(" 2147483647paper: %d\n", atoi(" 2147483647paper"));
// 	printf(" 2147483647paper: %d\n", ft_atoi(" 2147483647paper"));
// 	printf("      2147483650: %d\n", atoi(" 2147483650"));
// 	printf("      2147483650: %d\n", ft_atoi(" 2147483650"));
// 	printf("     32147483650: %d\n", atoi(" 32147483650"));
// 	printf("     32147483650: %d\n", ft_atoi(" 32147483650"));
// 	printf("-2147483648paper: %d\n", atoi(" -2147483648paper"));
// 	printf("-2147483648paper: %d\n", ft_atoi(" -2147483648paper"));
// 	printf("     -2147483650: %d\n", atoi(" -2147483650"));
// 	printf("     -2147483650: %d\n", ft_atoi(" -2147483650"));
// 	printf("   -322147483650: %d\n", atoi(" -322147483650"));
// 	printf("   -322147483650: %d\n", ft_atoi(" -322147483650"));
// 	printf("   -21474~=83650: %d\n", atoi(" -21474~=83650"));
// 	printf("   -21474~=83650: %d\n", ft_atoi(" -21474~=83650"));
// 	printf("  - 21474~=83650: %d\n", atoi(" - 21474~=83650"));
// 	printf("  - 21474~=83650: %d\n", ft_atoi(" - 21474~=83650"));
// 	printf("\n\t[LMAX LMIN]\n");
// 	printf("   lmax: %ld\n", LONG_MAX);
// 	printf("   lmin: %ld\n", LONG_MIN);
// 	printf("(i)lmax: %d\n", (int)LONG_MAX);
// 	printf("(i)lmin: %d\n", (int)LONG_MIN);
// 	printf("   lmax: %d\n", atoi(" 9223372036854775807"));
// 	printf("   lmax: %d\n", ft_atoi(" 9223372036854775807"));
// 	printf("   lmin: %d\n", atoi(" -9223372036854775808"));
// 	printf("   lmin: %d\n", ft_atoi(" -9223372036854775808"));
// 	printf(" lmax-1: %d\n", atoi(" 9223372036854775806"));
// 	printf(" lmax-1: %d\n", ft_atoi(" 9223372036854775806"));
// 	printf(" lmin+1: %d\n", atoi(" -9223372036854775807"));
// 	printf(" lmin+1: %d\n", ft_atoi(" -9223372036854775807"));
// 	printf(" lmax+3: %d\n", atoi(" 922337203685477580610"));
// 	printf(" lmax+3: %d\n", ft_atoi(" 9223372036854775810"));
// 	printf(" lmin-2: %d\n", atoi(" -9223372036854775810"));
// 	printf(" lmin-2: %d\n", ft_atoi(" -9223372036854775810"));
// 	return (0);
// }
