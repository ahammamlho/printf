/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:04:43 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/24 12:24:04 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"
// ft_convert_base.c
char	*ft_add_char_bonus(char *src, char c);
char	*ft_int_base_bonus(uintptr_t nbr, char *res);
char	*ft_int_32base_bonus(u_int32_t nbr, char *res, int is_lower);
//ft_unsigned_itoa.c
char	*ft_unsigned_itoa_bonus(unsigned int n);
//ft_printf_utile1.c
void	ft_print_char_bonus(char **str, char c, char **index, char *flags);
void	ft_print_string_bonus(char **str, char *s, char *flags);
void	ft_print_pointer_bonus(char **str, void *ptr, char *flags);
void	ft_print_decimal_bonus(char **str, int nbr);
void	ft_print_unsigned_decimal_bonus(char **str, int nbr);
//ft_printf_utile2.c
void	ft_print_num_hex_l_bonus(char **str, int nbr, int is_lower, char hash);
//ft_printf.c
int		ft_putresultat_bonus(char *result, char *index);
int		ft_printf_bonus(const char *str, ...);
void	ft_body_printf_bonus(char c, va_list list, char **res, char **ind, char *flags);
//ft_printf_flags_bonus.c
int     ft_nbrlen_bonus( int nbr);
void    ft_printf_flags_hash_bonus(const char *str, char **result, int *i, int value);
void    ft_printf_flags_plus_bonus(const char *str, char **result, int *i, int value);
int ft_char_in_strig(char *str, char c);



#endif