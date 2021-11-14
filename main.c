/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:55:07 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/14 16:13:53 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OR_
#include "ft_printf.h"
#endif
#include <stdio.h>
#include <stddef.h>
#include <limits.h>

#define ARG "{%p}\n", &ret_or
// #define ARG "Dans %s%cil y a%s%i letres", "l'Alphabet", ' ', "", 29
// #define ARG "%saaa", ""

int	main(void)
{
	setbuf(stdout, NULL);
#ifndef FT_
	int ret_or = 0;

	printf("OR_");
	ret_or = printf(ARG);
	printf("[%d]\n", ret_or);
#endif
#ifndef OR_
	int ret_ft = 0;

	ft_putstr("\n\nFT_");
	ret_ft = ft_printf(ARG);
	printf("[%d]\n", ret_ft);
#endif
	return (0);
}
