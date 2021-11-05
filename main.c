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

#define ARG "test123\t13123\nUwU"

int	main(void)
{
#ifndef OR_
	int ret_ft = 0;

	ft_putstr("FT_\n");
	ret_ft = ft_printf(ARG);
	printf("\n[%d]\n\n", ret_ft);
#endif
#ifndef FT_
	int ret_or = 0;

	printf("OR_\n");
	ret_or = printf(ARG);
	printf("\n[%d]\n", ret_or);
#endif
	return (0);
}
