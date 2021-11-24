/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utile1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:59:56 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/24 12:58:06 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_add_n_char(char **res, char c, int n)
{
	int i;

	i = -1;
	if (n > 0)
	{
		while (++i < n)
			*res = ft_add_char_bonus(*res, c);
	}
}

void	ft_flags_left_min(char **str, char *temp, char *flags)
{
	int i;

	i = -1;
	if (ft_char_in_strig(flags,'-') != -1)
	{
		while (temp[++i])
			*str = ft_add_char_bonus(*str, temp[i]);
		if (ft_strlen(flags) != 0)
			ft_add_n_char(str, ' ', ft_atoi(flags + 1) - ft_strlen(temp));
	}
	else
	{
		ft_add_n_char(str, ' ', ft_atoi(flags) - ft_strlen(temp));
		while (temp[++i])
			*str = ft_add_char_bonus(*str, temp[i]);
	}
}

void	ft_print_char_bonus(char **str, char c, char **index, char *flags)
{
	char	*res;
	int		i;
	char *temp;

	res = 0;
	temp = ft_calloc(1, sizeof(char));
	i = -1;
	if (c == 0)
	{
		if (ft_char_in_strig(flags,'-') == -1)
			res = ft_itoa(ft_strlen(*str) + ft_atoi(flags) - 1);
		else
			res = ft_itoa(ft_strlen(*str));
		while (res[++i])
			*index = ft_add_char_bonus(*index, res[i]);
		*index = ft_add_char_bonus(*index, '|');
		free(res);
	}
	if (c)
		temp = ft_add_char_bonus(temp, c);
	else
		temp = ft_add_char_bonus(temp, 'c');
	ft_flags_left_min(str, temp, flags);
	free(temp);	
}

void	ft_print_string_bonus(char **str, char *s, char *flags)
{
	char	*temp;

	if (s == NULL)
		temp = ft_strdup("(null)");
	else
		temp = ft_strdup(s);
	if (ft_char_in_strig(flags,'.') != -1)
		temp = ft_substr(temp, 0 , ft_atoi(flags + ft_char_in_strig(flags,'.') + 1));
	ft_flags_left_min( str, temp, flags);
	free(temp);
}

void	ft_print_pointer_bonus(char **str, void *ptr, char *flags)
{
	int			i;
	char		*res;
	char		*temp;
	uintptr_t	p;

	p = (uintptr_t)ptr;
	res = ft_calloc(1, sizeof(char));
	temp = ft_calloc(1, sizeof(char));
	res = ft_int_base_bonus(p, res);
	i = -1;
	temp = ft_add_char_bonus(temp, '0');
	temp = ft_add_char_bonus(temp, 'x');
	if (!ptr)
		temp = ft_add_char_bonus(temp, '0');
	while (ptr && res[++i])
		temp = ft_add_char_bonus(temp, res[i]);
	ft_flags_left_min(str, temp, flags);
	free(temp);
	free(res);
}

void	ft_print_decimal_bonus(char **str, int nbr)
{
	char	*s_nbr;
	int		i;

	i = -1;
	s_nbr = ft_itoa(nbr);
	while (s_nbr[++i])
		*str = ft_add_char_bonus(*str, s_nbr[i]);
	free(s_nbr);
}

void	ft_print_unsigned_decimal_bonus(char **str, int nbr)
{
	char	*s_nbr;
	int		i;

	i = -1;
	s_nbr = ft_unsigned_itoa_bonus(nbr);
	while (s_nbr[++i])
		*str = ft_add_char_bonus(*str, s_nbr[i]);
	free(s_nbr);
}
