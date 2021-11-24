/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utile2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:05:54 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/23 17:39:27 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_num_hex_l_bonus( char **str, int nbr, int is_lower, char hash)
{
	char	*s_nbr;
	int		i;

	if (nbr == 0)
	{
		if (hash)
			*str = ft_add_char_bonus(*str, ' ');
		*str = ft_add_char_bonus(*str, '0');
	}
	else
	{
		if (hash)
		{
			*str = ft_add_char_bonus(*str, '0');
			*str = ft_add_char_bonus(*str, hash);
			if (hash == 'x')
				is_lower = 1;
			else
				is_lower = 0;
		}
		s_nbr = ft_calloc(1, sizeof(char));
		s_nbr = ft_int_32base_bonus(nbr, s_nbr, is_lower);
		i = -1;
		while (s_nbr[++i])
			*str = ft_add_char_bonus(*str, s_nbr[i]);
		free(s_nbr);
	}
}
