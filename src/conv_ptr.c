/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:05:58 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/14 16:38:17 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_p(va_list *arg, t_data *d)
{
	d->skip++;
	if (!vect_cat(&d->v, "0x"))
		return (F_EXIT_FAILURE);
	if (!vect_ultohex_cat((unsigned long)va_arg(*arg, unsigned long), &d->v, 0))
		return (F_EXIT_FAILURE);
	return (F_EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_x(va_list *arg, t_data *d)
{
	d->skip++;
	if (!vect_utohex_cat((unsigned int)va_arg(*arg, unsigned int), &d->v, 0))
		return (F_EXIT_FAILURE);
	return (F_EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_xx(va_list *arg, t_data *d)
{
	d->skip++;
	if (!vect_utohex_cat((unsigned int)va_arg(*arg, unsigned int), &d->v, 1))
		return (F_EXIT_FAILURE);
	return (F_EXIT_SUCCESS);
}
