/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:55:07 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/03 17:05:54 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

#define ARG "%c", 'c'

int	main(void)
{
#ifndef OR_
	ft_putstr("FT_[");
	ft_printf(ARG);
	ft_putstr("]\n");
#endif
#ifndef FT_
	printf("OR_[");
	printf(ARG);
	printf("]\n");
#endif
	return (0);
}
