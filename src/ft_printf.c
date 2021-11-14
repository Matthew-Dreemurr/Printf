/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:29:13 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/14 16:46:51 by mahadad          ###   ########.fr       */
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
	d->skip = 0;
	d->ft_printf_return = 0;
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
		return (PRNTF_EXIT_FAILURE);
	while (str[d.skip])
	{
		if (str[d.skip] != '%')
		{
			if (!vect_push(&d.v, str[d.skip]))
				return (free_return(d.v.buff, PRNTF_EXIT_FAILURE));
			d.skip++;
		}
		else
			if (!conversion_manager(str, &arg, &d))
				return (free_return(d.v.buff, PRNTF_EXIT_FAILURE));
	}
	d.ft_printf_return += putstr_ret_int(d.v.buff);
	free(d.v.buff);
	return (d.ft_printf_return);
}
