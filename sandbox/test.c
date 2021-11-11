/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:03:56 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/11 16:31:45 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../src/libft/libft.h"
#include <stdio.h>

// int	test_width_len()
// {
// 	t_data d;

// 	d.skip = 0;
// 	d.width = 0;
// 	char *str = "badbb%123aaaaa";
// 	while (!ft_isdigit(*str))
// 		str++;
// 	width_len(str, &d);
// 	printf("[%d]\n", d.skip);
// 	str += d.skip;
// 	puts(str);
// 	return (0);
// }

int	test_flag_signed()
{
	printf("|% -4d|\n", 1);
	return (0);
}

int	main(void)
{
	// return(test_width_len());
	return(test_flag_signed());
}