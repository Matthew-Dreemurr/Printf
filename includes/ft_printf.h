/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:26:34 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/11 16:28:20 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* _.-=+=-._.-=+=-._[ Macro ]_.-=+=-._.-=+=-._ */

# define F_ARR_CONV_CONV     9
# define F_ARR_CONV_FLAG     6
# define PRNT_EXIT_FAILURE  -1
# define PRNT_EXIT_SUCCESS  -1

/* _.-=+=-._.-=+=-._[ Includes ]_.-=+=-._.-=+=-._ */

/* -[ Malloc, Free ]-*/
# include <stdarg.h>
/* -[ Va_start, Va_arg, Va_copy, Va_arg ]-*/
# include <stdlib.h>
/* -[ Write ]-*/
# include <unistd.h>

/* _.-=+=-._.-=+=-._[ Typedef ]_.-=+=-._.-=+=-._ */

/**
 * @brief test
 * @param r      `int`     Return value.
 * @param minus  `int`     Flag `-`.
 * @param zero   `int`     Flag `0`.
 * @param point  `int`     Flag `.`.
 * @param prefix `int`     Flag `#`.
 * @param unsign `int`     Flag ` `.
 * @param sing   `int`     Flag `+`.
 * @param width  `int`  The size of minimum field.
 * @param skip   `int`  The char to skip in `str`.
 *
 */
typedef struct s_data
{
	int		r;
	int		minus;
	int		zero;
	int		point;
	int		prefix;
	int		unsign;
	int		sign;
	int		width;
	int		skip;
}				t_data;

/**
 * @brief Function pointer.
 */
typedef int	(*t_function_ptr)(const char *str, va_list *arg, t_data *d);

/* _.-=+=-._.-=+=-._[ Prototypes ]_.-=+=-._.-=+=-._ */

/* -=-=-=-=-=-=-=-=-=- File: [ src/ft_printf.c ] -=-=-=-=-=-=-=-=-=- */

void	data_init(t_data *d);
int		ft_printf(const char *str, ...);

/* -=-=-=-=-=-=-=-=-=- File: [ src/arg_manager.c ] -=-=-=-=-=-=-=-=-=- */

int		conversion_manager(const char *str, va_list *av, t_data *d);
int		arg_manager(const char *str, va_list *av, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_char.c ] -=-=-=-=-=-=-=-=-=- */

int		conv_c(const char *str, va_list *arg, t_data *d);
int		conv_s(const char *str, va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_digit.c ] -=-=-=-=-=-=-=-=-=- */

int		conv_d(const char *str, va_list *arg, t_data *d);
int		conv_i(const char *str, va_list *arg, t_data *d);
int		conv_u(const char *str, va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_ptr.c ] -=-=-=-=-=-=-=-=-=- */

int		conv_p(const char *str, va_list *arg, t_data *d);
int		conv_x(const char *str, va_list *arg, t_data *d);
int		conv_xx(const char *str, va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_utils.c ] -=-=-=-=-=-=-=-=-=- */

int		conv_invalid(const char *str, va_list *arg, t_data *d);
int		 width_len(const char *str, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/flag_padding.c ] -=-=-=-=-=-=-=-=-=- */

int		flag_minus(const char *str, va_list *arg, t_data *d);
int		flag_zero(const char *str, va_list *arg, t_data *d);
int		flag_point(const char *str, va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/flag_prefix.c ] -=-=-=-=-=-=-=-=-=- */

int		flag_prefix(const char *str, va_list *arg, t_data *d);
int		flag_unsign(const char *str, va_list *arg, t_data *d);
int		flag_sing(const char *str, va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/libft/. ] -=-=-=-=-=-=-=-=-=- */

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		putstr_ret_int(char *s);
int		putchar_ret_int(char c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif