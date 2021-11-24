/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utile1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:59:56 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/23 01:03:46 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char **str, char c, char **index)
{
	char	*res;
	int		i;

	res = 0;
	i = -1;
	if (c == 0)
	{
		res = ft_itoa(ft_strlen(*str));
		while (res[++i])
			*index = ft_add_char(*index, res[i]);
		*index = ft_add_char(*index, '|');
		free(res);
	}
	else
		*str = ft_add_char(*str, c);
}

void	ft_print_string(char **str, char *s)
{
	int		len;
	int		i;
	char	*nul;

	nul = "(null)";
	i = -1;
	if (!s)
		while (nul[++i])
			*str = ft_add_char(*str, nul[i]);
	else
	{
		len = ft_strlen(*str);
		while (s[++i])
			*str = ft_add_char(*str, s[i]);
	}
}

void	ft_print_pointer(char **str, void *ptr)
{
	int			len;
	int			i;
	char		*res;
	uintptr_t	p;

	p = (uintptr_t)ptr;
	res = ft_calloc(1, sizeof(char));
	res = ft_int_base(p, res);
	len = ft_strlen(*str);
	i = -1;
	*str = ft_add_char(*str, '0');
	*str = ft_add_char(*str, 'x');
	if (!ptr)
		*str = ft_add_char(*str, '0');
	while (ptr && res[++i])
		*str = ft_add_char(*str, res[i]);
	if (res)
		free(res);
}

void	ft_print_decimal(char **str, int nbr)
{
	char	*s_nbr;
	int		i;

	i = -1;
	s_nbr = ft_itoa(nbr);
	while (s_nbr[++i])
		*str = ft_add_char(*str, s_nbr[i]);
	free(s_nbr);
}

void	ft_print_unsigned_decimal(char **str, int nbr)
{
	char	*s_nbr;
	int		i;

	i = -1;
	s_nbr = ft_unsigned_itoa(nbr);
	while (s_nbr[++i])
		*str = ft_add_char(*str, s_nbr[i]);
	free(s_nbr);
}