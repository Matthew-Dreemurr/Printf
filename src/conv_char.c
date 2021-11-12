/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:32:52 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/12 14:46:18 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print a singlecharacter.
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_c(const char *str, va_list *arg, t_data *d)
{
	char	c;
	int		ret;


	(void)str;
	c = (char)va_arg(*arg, int);
	ret = vect_push(&d->v, c);
	if (!ret)
		return (F_EXIT_FAILURE);
	d->r++;
	d->skip++;
	return (F_EXIT_SUCCESS);
}

/**
 * @brief Print astring of characters.
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_s(const char *str, va_list *arg, t_data *d)
{
	char	*s;
	int		ret;


	(void)str;
	s = (char *)va_arg(*arg, char *);
	ret = vect_cat(&d->v, s);
	if (!ret)
		return (F_EXIT_FAILURE);
	d->r += ret;
	d->skip++;
	return (F_EXIT_SUCCESS);
}

/**
 * @brief Print a singlecharacter `%`.
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_percent(const char *str, va_list *arg, t_data *d)
{
	int	ret;

	(void)str;
	(void)arg;
	ret = vect_push(&d->v, '%');
	if (!ret)
		return (F_EXIT_FAILURE);
	d->r++;
	d->skip++;
	return (F_EXIT_SUCCESS);
}