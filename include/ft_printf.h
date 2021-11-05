/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:26:34 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/05 14:10:20 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* _.-=+=-._.-=+=-._[ Defines ]_.-=+=-._.-=+=-._ */

#define F_PTR_ARG 9

/* _.-=+=-._.-=+=-._[ Includes ]_.-=+=-._.-=+=-._ */

/* -[ Malloc, Free ]-*/
#include <stdarg.h>
/* -[ Va_start, Va_arg, Va_copy, Va_arg ]-*/
#include <stdlib.h>
/* -[ Write ]-*/
#include <unistd.h>

/* _.-=+=-._.-=+=-._[ Typedef ]_.-=+=-._.-=+=-._ */

/**
 * @brief test
 * @param r Return value `int`
 * 
 */
typedef struct	s_data
{
	int		r;
	size_t	skip;
}				t_data;

/**
 * @brief Function pointer.
 *
 */
typedef int (*t_function_ptr)(const char *str, va_list *arg, t_data *d);

/* _.-=+=-._.-=+=-._[ Prototypes ]_.-=+=-._.-=+=-._ */


/* -=-=-=-=-=-=-=-=-=- File: [ src/ft_printf.c ] -=-=-=-=-=-=-=-=-=- */

/**
 * @brief The main function
 * 
 * @param ...
 * @return int
 */
int	ft_printf(const char *, ...);

/* -=-=-=-=-=-=-=-=-=- File: [ src/arg_manager.c ] -=-=-=-=-=-=-=-=-=- */

/**
 * @brief 
 * 
 * @return int Rerun `0` if error else `!0`.
 */
int	conversion_manager(const char *str, va_list *av, t_data *d);

/**
 * @brief 
 * 
 * @return int  int Rerun `0` if error else `!0`.
 */
int	arg_manager(const char *str, va_list *av, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_char.c ] -=-=-=-=-=-=-=-=-=- */

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_c(const char *str, va_list *arg, t_data *d);

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_s(const char *str, va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_digit.c ] -=-=-=-=-=-=-=-=-=- */

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_d(const char *str, va_list *arg, t_data *d);

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_i(const char *str, va_list *arg, t_data *d);

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_u(const char *str, va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_ptr.c ] -=-=-=-=-=-=-=-=-=- */

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_p(const char *str, va_list *arg, t_data *d);

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_x(const char *str, va_list *arg, t_data *d);

/**
 * @brief 
 * 
 * @return int `0` if error else `!0`.
 */
int	conv_xx(const char *str, va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_utils.c ] -=-=-=-=-=-=-=-=-=- */

/**
 * @brief 
 * 
 * @return int Return `1`
 */
int	conv_invalid(const char *str, va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/libft/. ] -=-=-=-=-=-=-=-=-=- */

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		putstr_ret_int(char *s);
int		putchar_ret_int(char c);

#endif