/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:03:00 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/03 17:08:45 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	agr_manager(const char *str, va_list *av)
{
	(void)str;
	(void)av;
	ft_putstr("ARG CALL\n");
	return (1);
}