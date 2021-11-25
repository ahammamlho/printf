/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:04:43 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/25 13:59:21 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include "libft/libft.h"

// ft_convert_base.c
char	*ft_add_char(char *src, char c);
char	*ft_int_base(uintptr_t nbr, char *res);
char	*ft_int_32base(u_int32_t nbr, char *res, int is_lower);
//ft_unsigned_itoa.c
char	*ft_unsigned_itoa(unsigned int n);
//ft_printf_utile.c
int		ft_nbrlen( int nbr);
//ft_printf_csp.c
void	ft_print_char(char **str, char c, char **index, char *flags);
void	ft_print_string(char **str, char *s, char *flags);
void	ft_print_pointer(char **str, void *ptr, char *flags);
//ft_printf_diu.c
void	ft_print_decimal(char **str, int nbr, char *flags);
void	ft_print_unsigned_decimal(char **str, int nbr, char *flags);
//ft_printf_xx.c
void	ft_print_num_hex_l(char **str, int nbr, int is_lower, char *flags);
//ft_printf.c
int		ft_printf(const char *str, ...);
//ft_flags1
int		ft_char_in_strig(char *str, char c);
void	ft_add_flags(const char *str, int *i, char **flags);
void	ft_add_n_char(char **res, char c, int n);
int		ft_is_flag_zero(char *flags);
int		ft_min_width(char *flags, int idx);
//flags2
void	ft_flags_left_min(char **str, char *temp, char *flags);
void	ft_flags_left_min_decimal(char **str, char *temp, char *flags, char c);
void	ft_flags_left_min_hex(char **str, char *temp, char *flags, char c);
void	ft_free(char **p1, char **p2, char **p3);
void	ft_flags_left_min_char(char **str, char c, char *flags);

#endif