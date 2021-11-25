/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:21:52 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/24 23:45:25 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_decimal(char **str, int nbr, char *flags)
{
	char	*s_nbr;
	char	*temp;
	int		i;

	i = -1;
	temp = (char *)ft_calloc(1, sizeof(char));
	if (nbr == INT_MIN)
		s_nbr = ft_strdup("2147483648");
	else if (nbr < 0)
		s_nbr = ft_itoa(-nbr);
	else
		s_nbr = ft_itoa(nbr);
	if (ft_char_in_strig(flags,' ') != -1 && nbr >= 0)
		temp = ft_add_char(temp, ' ');
	else if (ft_char_in_strig(flags,'+') != -1 && nbr >= 0)
		temp = ft_add_char(temp, '+');
	else if (nbr < 0 || nbr == INT_MIN)
		temp = ft_add_char(temp, '-');
	if(ft_char_in_strig(flags,'.') != -1)
		ft_add_n_char(&temp, '0', ft_atoi(flags + ft_char_in_strig(flags, '.') + 1)
							 - ft_strlen(s_nbr));
	else if (ft_is_flag_zero(flags) != -1)
		ft_add_n_char(&temp, '0', ft_atoi(flags + ft_min_width(flags, ft_is_flag_zero(flags)) + 1)
						- ft_strlen(temp) - ft_strlen(s_nbr));			 
	while (s_nbr[++i] && nbr != 0)
		temp = ft_add_char(temp, s_nbr[i]);
	if (nbr == 0 && ft_strlen(flags) == 0)
	 	temp = ft_add_char(temp, '0');
	else if (nbr == 0 && ft_char_in_strig(flags, '.') == -1)
	 	temp = ft_add_char(temp, '0');
	else if (nbr == 0 && ft_char_in_strig(flags, '.') != -1 && ft_atoi(flags + ft_char_in_strig(flags, '.') + 1) > 0)
		temp = ft_add_char(temp, '0');
	ft_flags_left_min_decimal(str, temp, flags, ' ');
	free(s_nbr);
	free(temp);
}

void	ft_print_unsigned_decimal(char **str, int nbr, char *flags)
{
	char	*s_nbr;
	char	*temp;
	int		i;

	i = -1;
	temp = (char *)ft_calloc(1, sizeof(char));
	s_nbr = ft_unsigned_itoa(nbr);
	if(ft_char_in_strig(flags,'.') != -1)
		ft_add_n_char(&temp, '0', ft_atoi(flags + ft_char_in_strig(flags, '.') + 1)
							 - ft_strlen(s_nbr));
	else if (ft_is_flag_zero(flags) != -1)
		ft_add_n_char(&temp, '0', ft_atoi(flags + ft_min_width(flags, ft_is_flag_zero(flags)) + 1)
						- ft_strlen(temp) - ft_strlen(s_nbr));				 
	while (s_nbr[++i] && nbr != 0)
		temp = ft_add_char(temp, s_nbr[i]);
	if (nbr == 0 && ft_strlen(flags) == 0)
	 	temp = ft_add_char(temp, '0');
	else if (nbr == 0 && ft_char_in_strig(flags, '.') == -1)
	 	temp = ft_add_char(temp, '0');
	else if (nbr == 0 && ft_char_in_strig(flags, '.') != -1 && ft_atoi(flags + ft_char_in_strig(flags, '.') + 1) > 0)
		temp = ft_add_char(temp, '0');
	ft_flags_left_min_decimal(str, temp, flags, ' ');
	free(s_nbr);
	free(temp);
}

void	ft_print_num_hex_l(char **str, int nbr, int is_lower, char *flags)
{
	char	*s_nbr;
	char	*temp;
	int		i;

	i = -1;
	temp = (char *)ft_calloc(1, sizeof(char));
	s_nbr = ft_calloc(1, sizeof(char));
	s_nbr = ft_int_32base(nbr, s_nbr, is_lower);
	if(ft_char_in_strig(flags, '#') != -1 && nbr != 0)
	{
		temp = ft_add_char(temp, '0');
		if (is_lower)
			temp = ft_add_char(temp, 'x');
		else
			temp = ft_add_char(temp, 'X');
	}
	if(ft_char_in_strig(flags,'.') != -1)
		ft_add_n_char(&temp, '0', ft_atoi(flags + ft_char_in_strig(flags, '.') + 1)
							 - ft_strlen(s_nbr));
	else if (ft_is_flag_zero(flags) != -1)
		ft_add_n_char(&temp, '0', ft_atoi(flags + ft_min_width(flags, ft_is_flag_zero(flags)) + 1)
						- ft_strlen(temp) - ft_strlen(s_nbr));				 
	while (s_nbr[++i] && nbr != 0)
		temp = ft_add_char(temp, s_nbr[i]);
	//printf("------%d\n", ft_atoi(flags + ft_char_in_strig(flags, '.') + 1));
	if (nbr == 0 && ft_char_in_strig(flags, '.') != -1 && ft_atoi(flags + ft_char_in_strig(flags, '.') + 1) > 0) 
		;
	else if (nbr == 0 && ft_is_flag_zero(flags) != -1)
		;
	else if (nbr == 0)
	{
		temp = ft_add_char(temp, '0');
	}
	
	// else if (nbr == 0 && ft_char_in_strig(flags, '.') != -1 && )
	// 	temp = ft_add_char(temp, '0');
	ft_flags_left_min_hex(str, temp, flags, ' ');
	free(temp);
	free(s_nbr);
}//