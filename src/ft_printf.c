/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:29:13 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/12 13:09:00 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief 
 * 
 * @param str 
 * @param ret 
 * @return int 
 */
int	free_return(char *str, int ret)
{
	free (str);
	return (ret);
}

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
	int		vect_ret;

	va_start(arg, str);
	data_init(&d);
	if (!vect_init(&d.v, VEC_BUFFER_SIZE))
		return (PRNTF_EXIT_FAILURE);
	while (str[d.skip])//TODO check if str = "%%"
	{
		if (str[d.skip] != '%')
		{
			vect_ret = vect_push(&d.v, str[d.skip]);
			if (!vect_ret)
				return (free_return(d.v.buff, PRNTF_EXIT_FAILURE));
			d.r += vect_ret;
		}
		else
			if (!conversion_manager(str, &arg, &d))
				return (free_return(d.v.buff, PRNTF_EXIT_FAILURE));
		if (str[d.skip])
			d.skip++;
	}
	ft_putstr_fd(d.v.buff, STDOUT_FILENO);
	free(d.v.buff);
	return (d.r);
}
