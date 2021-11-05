/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:03:00 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/05 19:37:16 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 *  Index   Conv   Function
 *  ------|------|---------
 *   [0]  | %c   | conv_c
 *   [1]  | %s   | conv_s
 *   [2]  | %p   | conv_p
 *   [3]  | %d   | conv_d
 *   [4]  | %i   | conv_i
 *   [5]  | %u   | conv_u
 *   [6]  | %x   | conv_x
 *   [7]  | %X   | conv_xx
 *   [8]  | %` ` | conv_invalid
 *
 */

/**
 * @brief 
 * 
 * @return int Rerun `0` if error else `!0`.
 */
int	conversion_manager(const char *str, va_list *av, t_data *d)
{
	char					*conversion;
	int						index;
	static t_function_ptr	f[F_ARR_CONV_CONV] = {
		conv_c, conv_s, conv_p, conv_d, conv_i, conv_u, conv_x, conv_xx,
		conv_invalid
	};

	index = 0;
	conversion = "cspdiuxX";
	while (*conversion)
	{
		if (*conversion++ == *str)
		{
			if(!f[index](str, av, d))
				return (0);//ERROR
			break ;
		}
		index++;
	}
	if (!*conversion)
		if(!f[index](str, av, d))
				return (0);//ERROR
return (1);
}

/**
 * @brief 
 * 
 * @return int  int Rerun `0` if error else `!0`.
 */
int	arg_manager(const char *str, va_list *av, t_data *d)
{
	static t_function_ptr	f[F_ARR_CONV_FLAG] = {
		flag_minus, flag_zero, flag_point, flag_prefix, flag_unsign,
		flag_sing
	};
	char					*conversion;
	int						index;

	(void)conversion;
	(void)index;
	(void)f;
	d->skip = 0;
	if (ft_isdigit(*str))
		width_len(str, d);
	if (!conversion_manager(str, av, d))
		return (0);
	return (1);
}