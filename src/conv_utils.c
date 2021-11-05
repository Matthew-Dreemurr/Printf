/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:45:18 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/05 13:49:33 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	conv_invalid(const char *str, va_list *arg, t_data *d)
{
	(void)str;
	(void)arg;
	(void)d;
	return (1);
}