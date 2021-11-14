/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:45:18 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/14 17:20:51 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Dummy function.
 *
 * @return int Return `1`
 */
int	conv_invalid(va_list *arg, t_data *d)
{
	(void)arg;
	(void)d;
	return (F_EXIT_FAILURE);
}
