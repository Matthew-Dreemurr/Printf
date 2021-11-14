/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:26:34 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/14 16:12:13 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* _.-=+=-._.-=+=-._[ Macro ]_.-=+=-._.-=+=-._ */

# define F_ARR_CONV           10

# define PRNTF_EXIT_FAILURE   0
# define PRNT_EXIT_SUCCESS    0
# define PRINTF_NULL_CASE     "(null)"
# define F_EXIT_SUCCESS       1
# define F_EXIT_FAILURE       0


/* _.-=+=-._.-=+=-._[ Includes ]_.-=+=-._.-=+=-._ */

/* -[ Malloc, Free ]-*/
# include <stdarg.h>
/* -[ Va_start, Va_arg, Va_copy, Va_arg ]-*/
# include <stdlib.h>
/* -[ Write ]-*/
# include <unistd.h>

/* _.-=+=-._.-=+=-._[ Typedef ]_.-=+=-._.-=+=-._ */

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
 * @brief test
 * @param r          `int`     Return value.
 * @param minus      `int`     Flag `-`.
 * @param zero       `int`     Flag `0`.
 * @param point      `int`     Flag `.`.
 * @param prefix     `int`     Flag `#`.
 * @param unsign     `int`     Flag ` `.
 * @param sing       `int`     Flag `+`.
 * @param width      `int`  The size of minimum field.
 * @param skip       `int`  The char to skip in `str`.
 *
 */
typedef struct s_data
{
	int			minus;
	int			zero;
	int			point;
	int			prefix;
	int			unsign;
	int			sign;
	int			width;
	int			skip;
	t_vector	v;
}				t_data;

/**
 * @brief Function pointer.
 */
typedef int	(*t_function_ptr)(va_list *arg, t_data *d);

/* _.-=+=-._.-=+=-._[ Prototypes ]_.-=+=-._.-=+=-._ */

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

int	conv_d_i(va_list *arg, t_data *d);
int		conv_u(va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_ptr.c ] -=-=-=-=-=-=-=-=-=- */

int		conv_p(va_list *arg, t_data *d);
int		conv_x(va_list *arg, t_data *d);
int		conv_xx(va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/conv_utils.c ] -=-=-=-=-=-=-=-=-=- */

int		conv_invalid(va_list *arg, t_data *d);
int		 width_len(const char *str, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/flag_padding.c ] -=-=-=-=-=-=-=-=-=- */

int		flag_minus(va_list *arg, t_data *d);
int		flag_zero(va_list *arg, t_data *d);
int		flag_point(va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/flag_prefix.c ] -=-=-=-=-=-=-=-=-=- */

int		flag_prefix(va_list *arg, t_data *d);
int		flag_unsign(va_list *arg, t_data *d);
int		flag_sing(va_list *arg, t_data *d);

/* -=-=-=-=-=-=-=-=-=- File: [ src/libft/. ] -=-=-=-=-=-=-=-=-=- */

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
int		putstr_ret_int(char *s);
int		putchar_ret_int(char c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	len_chrchr(char *str, char c);
char	*ft_strchr(const char *s, int c);
size_t	strlen_protect(const char *s);
void	rev_char_arr(char *str, size_t size);
/*=={ src/vector }==*/

# define VEC_EXIT_FAILURE ((int)0)
# define VEC_EXIT_SUCCESS ((int)1)
# define VEC_BUFFER_SIZE  ((unsigned long)256)

int			vect_init(t_vector *v, size_t size);
int			vect_resize(t_vector *v, size_t size);
int			vect_cat(t_vector *v, char *str);
int			vect_push(t_vector *v, char c);
char		*vect_itoa_cat(int n, t_vector *v);
char		*vect_utoa_cat(unsigned int n, t_vector *v);
char		*vect_utohex_cat(unsigned int n, t_vector *v, int upper);
char	*vect_ultohex_cat(size_t n, t_vector *v, int upper);

#endif