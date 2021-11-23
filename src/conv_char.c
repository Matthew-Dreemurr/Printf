/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:32:52 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/23 13:49:57 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print a singlecharacter.
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_c(va_list *arg, t_data *d)
{
	char	c;

	d->skip++;
	c = (char)va_arg(*arg, int);
	if (!vect_push(&d->v, c))
		return (F_EXIT_FAILURE);
	return (F_EXIT_SUCCESS);
}

/**
 * @brief Print astring of characters.
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_s(va_list *arg, t_data *d)
{
	char	*s;

	d->skip++;
	s = (char *)va_arg(*arg, char *);
	if (!s)
	{
		if (!vect_cat(&d->v, PRINTF_NULL_CASE))
			return (F_EXIT_FAILURE);
	}
	else if (!vect_cat(&d->v, s))
		return (F_EXIT_FAILURE);
	return (F_EXIT_SUCCESS);
}

/**
 * @brief Print a singlecharacter `%`.
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_percent(va_list *arg, t_data *d)
{
	d->skip++;
	(void)arg;
	if (!vect_push(&d->v, '%'))
		return (F_EXIT_FAILURE);
	return (F_EXIT_SUCCESS);
}
