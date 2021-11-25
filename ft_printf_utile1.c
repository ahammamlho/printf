/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utile1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:36:37 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/24 19:45:18 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen( int nbr)
{
	int	len;
	int	mod;

	len = 1;
	if (nbr == 0)
		return (1);
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



// void ft_printf_flags_plus_bonus(const char *str, char **result, int *i, int value)
// {
// 	int j;
	
// 	j = 1;
// 	if (value > 0)
// 		*result = ft_add_char_bonus(*result, str[(*i) + 1]);
// 	ft_print_decimal_bonus(result, value);
// 	if (str[(*i) + 1] == ' ')
// 		while (str[(*i) + 1 + j] && str[(*i) + 1 + j] == ' ')
// 			j++;
// 	*i = *i + j;
// }