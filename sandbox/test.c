/**
 * @file test.c
 * @author Matthew-Dreemurr
 * @date 2021-11-04
 */

#include "../include/ft_printf.h"
#include "../src/libft/libft.h"
#include <stdio.h>

int	main(void)
{

	printf("[%d]\n", putstr_ret_int(NULL));
	return (0);
}