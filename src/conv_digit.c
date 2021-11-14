/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:01:32 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/14 16:38:03 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print a decimal (base 10) number.
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_d_i(va_list *arg, t_data *d)
{
	d->skip++;
	if (!vect_itoa_cat((int)va_arg(*arg, int), &d->v))
		return (F_EXIT_FAILURE);
	return (F_EXIT_SUCCESS);
}

/**
 * @brief Print an unsigned decimal (base 10) number
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_u(va_list *arg, t_data *d)
{
	d->skip++;
	if (!vect_utoa_cat((unsigned int)va_arg(*arg, unsigned int), &d->v))
		return (F_EXIT_FAILURE);
	return (F_EXIT_SUCCESS);
}
