/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:55:07 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/12 16:59:55 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OR_
#include "ft_printf.h"
#endif
#include <stdio.h>

#define ARG "Dans %s%cil y a%s%i letres", "l'Alphabet", ' ', NULL, 29
// #define ARG "Dans %s%cil y a%s%i letres", "l'Alphabet", ' ', "", 29
// #define ARG "%saaa", ""

int	main(void)
{
	setbuf(stdout, NULL);
#ifndef FT_
	int ret_or = 0;

	printf("OR_\n");
	ret_or = printf(ARG);
	printf("\n[%d]\n", ret_or);
#endif
#ifndef OR_
	int ret_ft = 0;

	ft_putstr("FT_\n");
	ret_ft = ft_printf(ARG);
	printf("\n[%d]\n\n", ret_ft);
#endif
	return (0);
}
