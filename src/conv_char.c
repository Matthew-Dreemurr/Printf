/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:32:52 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/11 17:53:01 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_c(const char *str, va_list *arg, t_data *d)
{
	(void)str;
	(void)arg;
	(void)d;
	ft_putstr("conv_c");
	return (1);
}

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_s(const char *str, va_list *arg, t_data *d)
{
	(void)str;
	(void)arg;
	(void)d;
	ft_putstr("conv_s");
	return (1);
}

int	conv_percent(const char *str, va_list *arg, t_data *d)
{
	(void)str;
	(void)arg;
	(void)d;
	ft_putstr("conv_percent");
	d->r += vect_push(&d->v, '%');//TODO how to check failure
	return (F_EXIT_SUCCESS);
}