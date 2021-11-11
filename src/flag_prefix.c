/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:34:02 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/11 17:01:46 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_prefix(const char *str, va_list *arg, t_data *d)
{
	(void)arg;
	(void)str;
	(void)d;
	ft_putstr("flag_prefix\n");
	return (0);
}

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_unsign(const char *str, va_list *arg, t_data *d)
{
	(void)arg;
	(void)str;
	(void)d;
	ft_putstr("flag_unsign\n");
	return (0);
}

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_sing(const char *str, va_list *arg, t_data *d)
{
	(void)arg;
	(void)str;
	(void)d;
	ft_putstr("flag_sing\n");
	return (0);
}
