/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:05:58 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/05 19:08:30 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_p(const char *str, va_list *arg, t_data *d)
{
	(void)str;
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
int	conv_x(const char *str, va_list *arg, t_data *d)
{
	(void)str;
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
int	conv_xx(const char *str, va_list *arg, t_data *d)
{
	(void)str;
	(void)arg;
	(void)d;
	ft_putstr("conv_X");
	return (1);
}
