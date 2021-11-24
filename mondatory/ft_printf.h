/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:04:43 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/23 11:28:18 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../bonus/ft_printf_bonus.h"
# include "../libft/libft.h"
// ft_convert_base.c
void	ft_free(char **ptr);
char	*ft_add_char(char *src, char c);
char	*ft_int_base(uintptr_t nbr, char *res);
char	*ft_int_32base(u_int32_t nbr, char *res, int is_lower);
//ft_unsigned_itoa.c
char	*ft_unsigned_itoa(unsigned int n);
//ft_printf_utile1.c
void	ft_print_char(char **str, char c, char **index);
void	ft_print_string(char **str, char *s);
void	ft_print_pointer(char **str, void *ptr);
void	ft_print_decimal(char **str, int nbr);
void	ft_print_unsigned_decimal(char **str, int nbr);
//ft_printf_utile2.c
// static int	ft_nbrlen( int nbr);
void	ft_print_num_hex_l(char **str, int nbr, int is_lower);
//ft_printf.c
int		ft_putresultat(char *result, char *index);
int		ft_printf(const char *str, ...);

#endif