/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:29:13 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/03 17:08:14 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;

	va_start(arg, str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str);
		else if (*++str == '%')
				ft_putchar(*str++);
		else
			if (!agr_manager(str, &arg))
				return (1); //ERROR
		str++;
	}
	return (0);
}