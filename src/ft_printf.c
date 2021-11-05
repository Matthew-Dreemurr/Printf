/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:29:13 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/05 14:20:16 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_data	d;

	va_start(arg, str);
	while (*str)
	{
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