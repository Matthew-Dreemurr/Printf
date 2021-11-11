/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:29:13 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/11 17:53:44 by mahadad          ###   ########.fr       */
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
	if (!vect_init(&d.v, VEC_BUFFER_SIZE))
		return (PRNT_EXIT_FAILURE);
	while (str[d.skip])//TODO check if str = "%%"
	{
		if (str[d.skip++] != '%')
			d.r += vect_push(&d.v, str[d.skip]);
		else
			if (!conversion_manager(str, &arg, &d))
				return (PRNT_EXIT_FAILURE);
	}
	ft_putstr_fd(d.v.buff, STDOUT_FILENO);
	free(d.v.buff);
	return (d.r);
}
