/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:29:13 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/08 16:17:21 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Init all var in t_data struct.
 * 
 */
void	data_init(t_data *d)
{
	d->r = 0;
	d->minus = 0;
	d->zero = 0;
	d->point = 0;
	d->prefix = 0;
	d->unsign = 0;
	d->sign = 0;
	d->width = 0;
	d->skip = 0;
}

/**
 * @brief The main function
 * 
 * @param ...
 * @return int
 */
int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_data	d;

	va_start(arg, str);
	data_init(&d);
	while (*str)
	{
		str += d.skip;
		if (*str != '%')
			d.r += putchar_ret_int(*str);
		else if (*str == '%' && *(str + 1) == '%')
				d.r += putchar_ret_int(*str++);
		else
			if (!arg_manager(++str, &arg, &d))
				return (-1); //Return ERROR
		if (!*str)
			break ;
		else
			str++;
	}
	return (d.r);
}