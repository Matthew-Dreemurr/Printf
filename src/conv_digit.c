/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:01:32 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/12 15:30:23 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/**
 * index   0  1  2  3  4  5  6  7  8  9  10 11
 *        [8][4][6][3][8][4][7][4][1][2][-][\0]
 * @brief Convert integer to string of char. (use malloc())
 * 
 * @param n The integer to convert.
 * @return  char* The string representing the integer. NULL if the
 *          allocation fails.
 *
 */
char	*vect_itoa_psuh(int n)
{
	char	buff[12];
	char	*ptr;
	size_t	nbr;

	nbr = (unsigned int []){n, -n}[n < 0];
	ptr = buff;
	if (nbr == 0)
		*ptr++ = '0';
	while (nbr > 0)
	{
		*ptr++ = (char)((nbr % 10) + '0');
		nbr /= 10;
	}
	*ptr++ = (char []){'\0', '-'}[n < 0];
	*ptr++ = '\0';
	//revesr str //TODO
	return (ptr);
}

/**
 * @brief Print a decimal (base 10) number.
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_d_i(const char *str, va_list *arg, t_data *d)
{
	char	*s;
	(void)str;
	(void)arg;
	(void)d;
	
	s = ft_itoa((int)va_arg(*arg, int));
	if (s)
	return (1);
}

/**
 * @brief Print an unsigned decimal (base 10) number
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_u(const char *str, va_list *arg, t_data *d)
{
	(void)str;
	(void)arg;
	(void)d;
	ft_putstr("conv_u");
	return (1);
}
