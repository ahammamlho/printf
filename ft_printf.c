/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:28:31 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/23 01:20:44 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen( int nbr)
{
	int	len;
	int	mod;

	len = 1;
	if (nbr > 0)
		mod = nbr / 10;
	else
	{
		mod = -nbr / 10;
		len++;
	}	
	while (mod > 0)
	{
		len++;
		mod = mod / 10;
	}
	return (len);
}

int	ft_putresultat(char *result, char *index)
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
			index = index + ft_nbrlen(nbr) + 1;
			nbr = ft_atoi(index);
		}
		write(1, &result[i], 1);
		i++;
	}
	return (len);
}

void	ft_body_printf(char c, va_list list, char **res, char **ind)
{
	if (c == 'c')
		ft_print_char(res, va_arg(list, int), ind);
	if (c == 's')
		ft_print_string(res, va_arg(list, char *));
	if (c == 'p')
		ft_print_pointer(res, va_arg(list, void *));
	if (c == 'd')
		ft_print_decimal(res, va_arg(list, int));
	if (c == 'i')
		ft_print_decimal(res, va_arg(list, int));
	if (c == 'u')
		ft_print_unsigned_decimal(res, va_arg(list, unsigned int));
	if (c == 'x')
		ft_print_num_hex_l(res, va_arg(list, int), 1);
	if (c == 'X')
		ft_print_num_hex_l(res, va_arg(list, int), 0);
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

	va_start(list, str);
	i = -1;
	result = (char *)ft_calloc(1, sizeof(char));
	index = (char *)ft_calloc(1, sizeof(char));
	while (str && str[++i])
	{
		if (str[i] == '%')
		{
			ft_body_printf(str[i + 1], list, &result, &index);
			i++;
		}
		else
			result = ft_add_char(result, str[i]);
	}
	va_end(list);
	len = ft_strlen(result) + ft_putresultat(result, index);
	free(result);
	free(index);
	return (len);
}

// int main()
// {
//     ft_printf("---%x---", NULL);
// }
