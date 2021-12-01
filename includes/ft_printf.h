/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:26:34 by mahadad           #+#    #+#             */
/*   Updated: 2021/12/01 16:13:48 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* _.-=+=-._.-=+=-._[ macro ]_.-=+=-._.-=+=-._ */

# define F_ARR_CONV           10

# define PRNTF_EXIT_FAILURE   0
# define PRNT_EXIT_SUCCESS    0

# define F_EXIT_SUCCESS       1
# define F_EXIT_FAILURE       0

# define PRINTF_NULL_CASE     "(null)"

/* _.-=+=-._.-=+=-._[ includes ]_.-=+=-._.-=+=-._ */

/* -[ malloc, free ]-*/
# include <stdarg.h>
/* -[ va_start, va_arg, va_copy, va_arg ]-*/
# include <stdlib.h>
/* -[ write ]-*/
# include <unistd.h>

/* _.-=+=-._.-=+=-._[ typedef ]_.-=+=-._.-=+=-._ */

/**
 * @brief s_vector struc to manage the memory of a char array.
 * 
 * @param len      Actual size use in buff.
 * @param max      Actual max size.
 * @param buff     The buffer is alloc whit (VEC_BUFFER_SIZE + 1).
 */
typedef struct s_vector
{
	size_t	len;
	size_t	max;
	char	*buff;
}				t_vector;

/**
 * @param r          `int`     Return value.
 * @param width      `int`  The size of minimum field.
 * @param skip       `int`  The char to skip in `str`.
 *
 */
typedef struct s_data
{
	int			ft_printf_return;
	int			skip;
	t_vector	v;
}				t_data;

/**
 * @brief Function pointer.
 */
typedef int	(*t_function_ptr)(va_list *arg, t_data *d);

/* _.-=+=-._.-=+=-._[ prototypes ]_.-=+=-._.-=+=-._ */

/* -=-=-=-=-=-=-=-=-=- File: [ src/ft_printf.c ] -=-=-=-=-=-=-=-=-=- */

int		free_return(char *str, int ret);
void	data_init(t_data *d);
int		ft_printf(const char *str, ...);

/* -=-=-=-=-=-=-=-=-=- File: [ src/arg_manager.c ] -=-=-=-=-=-=-=-=-=- */

int		conversion_manager(const char *str, va_list *av, t_data *d);
int		arg_manager(const char *str, va_list *av, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_char.c ] -=-=-=-=-=-=-=-=-=- */

int		conv_c(va_list *arg, t_data *d);
int		conv_s(va_list *arg, t_data *d);
int		conv_percent(va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_digit.c ] -=-=-=-=-=-=-=-=-=- */

int		conv_d_i(va_list *arg, t_data *d);
int		conv_u(va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_ptr.c ] -=-=-=-=-=-=-=-=-=- */

int		conv_p(va_list *arg, t_data *d);
int		conv_x(va_list *arg, t_data *d);
int		conv_xx(va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_utils.c ] -=-=-=-=-=-=-=-=-=- */

int		conv_invalid(va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/flag_padding.c ] -=-=-=-=-=-=-=-=-=- */

int		flag_minus(va_list *arg, t_data *d);
int		flag_zero(va_list *arg, t_data *d);
int		flag_point(va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/libft/. ] -=-=-=-=-=-=-=-=-=- */

int		putstr_ret_int(char *s);
size_t	strlen_protect(const char *s);
void	rev_char_arr(char *str, size_t size);

#endif