/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_digit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:01:32 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/05 14:26:14 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	conv_d(const char *str, va_list *arg, t_data *d)
{
	(void)str;
	(void)arg;
	(void)d;
	ft_putstr("conv_d");
	return (1);
}

int	conv_i(const char *str, va_list *arg, t_data *d)
{
	(void)str;
	(void)arg;
	(void)d;
	ft_putstr("conv_i");
	return (1);
}

int	conv_u(const char *str, va_list *arg, t_data *d)
{
	(void)str;
	(void)arg;
	(void)d;
	ft_putstr("conv_u");
	return (1);
}
