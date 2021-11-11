/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:29:13 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/11 16:41:58 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include "libft.h"

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
	t_vector v;

	va_start(arg, str);
	data_init(&d);
	vect_init(&v, VEC_BUFFER_SIZE);
	while (str[d.skip])
	{
		if (str[d.skip] != '%')
			d.r += vect_push(&v, str[d.skip]);
		else if (str[d.skip] == '%' && str[d.skip + 1] == '%')
			d.r += vect_push(&v, str[d.skip++]);
		else
			if (!arg_manager(&str[++d.skip], &arg, &d))
				return (PRNT_EXIT_FAILURE);
		if (!str[d.skip])
			break ;
		else
			d.skip++;
	}
	ft_putstr_fd(v.buff, STDOUT_FILENO);
	free(v.buff);
	return (d.r);
}
