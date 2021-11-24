/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:23:45 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/24 12:57:41 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/ft_printf_bonus.h"


int	ft_putresultat_bonus(char *result, char *index)
{
	int	i;
	int	nbr;
	int	len;

	i = 0;
	len = 0;
	nbr = ft_atoi(index);
	while (result && result[i])
	{
		if (ft_strlen(index) && nbr == i)
		{
			len++;
			write(1, "", 1);
			index = index + ft_nbrlen_bonus(nbr) + 1;
			nbr = ft_atoi(index);
		}
		else
			write(1, &result[i], 1);
		i++;
	}
	return (len);
}

void	ft_body_printf_bonus(char c, va_list list, char **res, char **ind, char *flags)
{
	if (c == 'c')
		ft_print_char_bonus(res, va_arg(list, int), ind, flags);
	if (c == 's')
		ft_print_string_bonus(res, va_arg(list, char *), flags);
	if (c == 'p')
		ft_print_pointer_bonus(res, va_arg(list, void *), flags);
	if (c == 'd')
		ft_print_decimal_bonus(res, va_arg(list, int));
	if (c == 'i')
		ft_print_decimal_bonus(res, va_arg(list, int));
	if (c == 'u')
		ft_print_unsigned_decimal_bonus(res, va_arg(list, unsigned int));
	if (c == 'x')
		ft_print_num_hex_l_bonus(res, va_arg(list, int), 1, 0);
	if (c == 'X')
		ft_print_num_hex_l_bonus(res, va_arg(list, int), 0, 0);
	if (c == '%')
		*res = ft_add_char_bonus(*res, '%');
}

void ft_printf_flags_hash_bonus(const char *str, char **result, int *i, int value)
{
	int nbr;
	char *s_value;
	unsigned int j;
	int k;
	char hash;

	j = -1;
	k = 0;
	s_value = ft_calloc(1, 1);
	s_value = ft_int_32base_bonus(value, s_value, 0);
	while (str[(*i) + k] != 'x' && str[(*i) + k] != 'X')
		k++;
	hash = str[(*i) + k];
	nbr = ft_atoi(str + (*i) + 2);
	if (nbr < 3)
		ft_print_num_hex_l_bonus(result, value, 1, hash);
	else
	{
		while(++j < (nbr - 2 - ft_strlen(s_value)))
			*result = ft_add_char_bonus(*result, ' ');
		ft_print_num_hex_l_bonus(result, value, 1, hash);
	}
	if (str[(*i) + 2] == 'x' || str[(*i) + 2] == 'X')
		(*i)--;
	*i = *i + ft_nbrlen_bonus(nbr) + 1;
}

int ft_char_in_strig(char *str, char c)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

void ft_add_flags(const char *str, int *i, char **flags)
{
	int j;

	j = 1;
	while (str[*i + j] != '%' && ft_char_in_strig("cspdiuxX", str[*i + j]) == -1)
	{
		*flags = ft_add_char_bonus(*flags, str[*i + j]);
		(*i)++;
	}
}

int	ft_printf_bonus(const char *str, ...)
{
	char		*result;
	va_list		list;
	int			i;
	int			len;
	char		*index;
	char 		*flags;

	va_start(list, str);
	i = -1;
	flags = (char *)ft_calloc(1, 1);
	result = (char *)ft_calloc(1, sizeof(char));
	index = (char *)ft_calloc(1, sizeof(char));
	while (str && str[++i])
	{
		if (str[i] == '%')
		{
			ft_add_flags(str, &i, &flags);
			//printf("flags ->%s\n", flags);
			ft_body_printf_bonus(str[i + 1], list, &result, &index, flags);
			i++;
		}
		else
			result = ft_add_char_bonus(result, str[i]);
	}
	va_end(list);
	len = ft_strlen(result) + ft_putresultat_bonus(result, index);
	free(result);
	free(index);
	return (len);
}

# define STR "--|%20p|--\n",&a

int main()
{
	char c = '\0';
	char *s = "ahamm";
	int a = 10;
	int u = ft_printf_bonus(STR);
	printf(STR);

}
