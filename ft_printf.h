/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:04:43 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/22 20:33:11 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "../libft/libft.h"

int ft_printf_len(const char *str, va_list list);
void ft_print_char(char **str, char c);
void	ft_print_string(char **str, char *s);
void ft_print_pointer(char **str, void *ptr);
void ft_print_num_hex_l(char **str, int nbr, int is_lower);
void ft_print_unsigned_decimal(char **str, int nbr);
static unsigned int	ft_unsigned_nbrlen(unsigned int nbr);
static char	*ft_unsigned_reverse(char *src);
char	*ft_unsigned_itoa(unsigned int n);
char	*ft_add_char(char *src, char c);
char	*ft_int_base(uintptr_t nbr, char *res);
void ft_print_decimal(char **str, int nbr);
char	*ft_int_32base(u_int32_t nbr, char *res, int is_lower);


#endif