/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:34:02 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/12 16:57:38 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_prefix(va_list *arg, t_data *d)
{
	(void)arg;
	(void)d;
	ft_putstr("flag_prefix\n");
	return (0);
}

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_unsign(va_list *arg, t_data *d)
{
	(void)arg;
	(void)d;
	ft_putstr("flag_unsign\n");
	return (0);
}

/**
 * @brief 
 * 
 * @return int 
 */
int	flag_sing(va_list *arg, t_data *d)
{
	(void)arg;
	(void)d;
	ft_putstr("flag_sing\n");
	return (0);
}
