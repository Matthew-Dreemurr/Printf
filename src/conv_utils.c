/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:45:18 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/11 17:30:29 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Dummy function.
 *
 * @return int Return `1`
 */
int	conv_invalid(const char *str, va_list *arg, t_data *d)
{
	(void)str;
	(void)arg;
	(void)d;
	ft_putstr("conv_invalid");
	return (F_EXIT_FAILURE);
}

/**
 * @brief init the size of `d->width` and set `d->skip` with len of the number.
 * 
 * @param str 
 * @param d 
 * 
 * @return The len of `nbr`.
 */
int width_len(const char *str, t_data *d)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = ft_atoi(str);
	d->width = nbr;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
