/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:05:58 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/12 16:57:18 by mahadad          ###   ########.fr       */
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
	(void)arg;
	(void)d;
	ft_putstr("conv_p");
	return (1);
}

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_x(va_list *arg, t_data *d)
{
	(void)arg;
	(void)d;
	ft_putstr("conv_x");
	return (1);
}

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_xx(va_list *arg, t_data *d)
{
	(void)arg;
	(void)d;
	ft_putstr("conv_X");
	return (1);
}
