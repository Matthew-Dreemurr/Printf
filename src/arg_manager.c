/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:03:00 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/14 17:29:03 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
 *   [8]  | %%   | conv_percent
 *   [9]  | %` ` | conv_invalid
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
	static t_function_ptr	f[F_ARR_CONV] = {
		conv_c, conv_s, conv_p, conv_d_i, conv_d_i, conv_u, conv_x, conv_xx,
		conv_percent, conv_invalid
	};

	index = 0;
	if (!str[d->skip])
		return (EXIT_FAILURE);
	d->skip++;
	conversion = "cspdiuxX%";
	while (conversion[index])
	{
		if (conversion[index] == str[d->skip])
		{
			if (!f[index](av, d))
				return (F_EXIT_FAILURE);
			break ;
		}
		index++;
	}
	if ((index + 1) == F_ARR_CONV)
		return (f[index](av, d));
	return (F_EXIT_SUCCESS);
}
