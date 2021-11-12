/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:09:50 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/12 16:57:30 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_minus(va_list *arg, t_data *d)
{
	(void)arg;
	(void)d;
	ft_putstr("flag_minus\n");
	return (0);
}

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_zero(va_list *arg, t_data *d)
{
	(void)arg;
	(void)d;
	ft_putstr("flag_zero\n");
	return (0);
}

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_point(va_list *arg, t_data *d)
{
	(void)arg;
	(void)d;
	ft_putstr("flag_point\n");
	return (0);
}
