/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:45:18 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/05 19:08:46 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
	return (1);
}

/**
 * @brief init the size of `d->width` and set `d->skip` with len of the number.
 * 
 * @param str 
 * @param d 
 */
void width_len(const char *str, t_data *d)
{
	int	nbr;

	nbr = ft_atoi(str);
	d->width = nbr;
	while (nbr)
	{
		nbr /= 10;
		d->skip++;
	}
}
