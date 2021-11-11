/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:09:50 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/11 17:01:14 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_minus(const char *str, va_list *arg, t_data *d)
{
	(void)arg;
	(void)str;
	(void)d;
	ft_putstr("flag_minus\n");
	return (0);
}

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_zero(const char *str, va_list *arg, t_data *d)
{
	(void)arg;
	(void)str;
	(void)d;
	ft_putstr("flag_zero\n");
	return (0);
}

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_point(const char *str, va_list *arg, t_data *d)
{
	(void)arg;
	(void)str;
	(void)d;
	ft_putstr("flag_point\n");
	return (0);
}
