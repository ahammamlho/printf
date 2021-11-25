/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:23:45 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/24 23:45:45 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_putresultat(char *result, char *index)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = ft_atoi(index);
	while (result && result[i])
	{
		if (ft_strlen(index) && nbr == i)
		{
			write(1, "", 1);
			index = index + ft_nbrlen(nbr) + 1;
			nbr = ft_atoi(index);
		}
		else
			write(1, &result[i], 1);
		i++;
	}
	return (i);
}

void	ft_body_printf(char c, va_list list, char **res, char **ind, char *flags)
{
	if (c == 'c')
		ft_print_char(res, va_arg(list, int), ind, flags);
	if (c == 's')
		ft_print_string(res, va_arg(list, char *), flags);
	if (c == 'p')
		ft_print_pointer(res, va_arg(list, void *), flags);
	if (c == 'd')
		ft_print_decimal(res, va_arg(list, int), flags);
	if (c == 'i')
		ft_print_decimal(res, va_arg(list, int), flags);
	if (c == 'u')
		ft_print_unsigned_decimal(res, va_arg(list, unsigned int), flags);
	if (c == 'x')
		ft_print_num_hex_l(res, va_arg(list, int), 1, flags);
	if (c == 'X')
		ft_print_num_hex_l(res, va_arg(list, int), 0, flags);
	if (c == '%')
		*res = ft_add_char(*res, '%');
}

int	ft_printf(const char *str, ...)
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
			ft_body_printf(str[i + 1], list, &result, &index, flags);
			i++;
		}
		else
			result = ft_add_char(result, str[i]);
		ft_bzero(flags, ft_strlen(flags));
	}
	va_end(list);
	len = ft_putresultat(result, index);
	free(result);
	free(index);
	free(flags);
	return (len);
}

// # define STR "--|%#10.4x|--\n", a
// int main()
// {
// 	char c = '\0';
// 	char *s = "ahamm";
// 	int a = 0;
// 	int u = ft_printf(STR);
//  	int t = printf(STR);
// 	//printf("%d---%d", u , t);
// }
