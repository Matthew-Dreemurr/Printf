/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:26:34 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/03 17:08:35 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* _.-=+=-._.-=+=-._[ Includes ]_.-=+=-._.-=+=-._ */

/* -[ Malloc, Free ]-*/
#include <stdarg.h>
/* -[ Va_start, Va_arg, Va_copy, Va_arg ]-*/
#include <stdlib.h>
/* -[ Write ]-*/
#include <unistd.h>

/* _.-=+=-._.-=+=-._[ Prototypes ]_.-=+=-._.-=+=-._ */

/* -=- File: [ src/ft_printf.c ] -=- */

/**
 * @brief test
 * @param int `r` Return value
 * 
 */
typedef struct	s_data
{
	int	r;
}				t_data;

/* -=- File: [ src/ft_printf.c ] -=- */

/**
 * @brief The main function
 * 
 * @param ...
 * @return int
 */
int	ft_printf(const char *, ...);

/* -=- File: [ src/arg_manager.c ] -=- */

/**
 * @brief 
 * 
 * @param str 
 * @param av 
 * @return int 
 */
int	agr_manager(const char *str, va_list *av, t_data *d);

/* -=- File: [ src/libft/. ] -=- */

void	ft_putchar(char c);
void	ft_putstr(char *s);
int	putstr_ret_int(char *s);
int	putchar_ret_int(char c);

#endif