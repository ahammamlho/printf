/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utile2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:05:54 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/23 01:04:43 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num_hex_l(char **str, int nbr, int is_lower)
{
	char	*s_nbr;
	int		i;

	if (nbr == 0)
		*str = ft_add_char(*str, '0');
	else
	{
		s_nbr = ft_calloc(1, sizeof(char));
		s_nbr = ft_int_32base(nbr, s_nbr, is_lower);
		i = -1;
		while (s_nbr[++i])
			*str = ft_add_char(*str, s_nbr[i]);
		free(s_nbr);
	}
}
