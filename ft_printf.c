/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:28:31 by lahammam          #+#    #+#             */
/*   Updated: 2021/11/22 20:33:04 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    char *result;
    va_list list;
    va_start(list, str);
    int len;
    int i = 0;
    
    result = (char *)ft_calloc(1, sizeof(char));
    while(str && str[i])
    {
        if (str[i] == '%')
        {
            if (str[i + 1] == 'c')
                 ft_print_char(&result, va_arg(list, int));
            if (str[i + 1] == 's')
                ft_print_string(&result, va_arg(list, char*));
            if (str[i + 1] == 'p')
                ft_print_pointer(&result, va_arg(list, void *));
            if (str[i + 1] == 'd')
                ft_print_decimal(&result, va_arg(list, int));
            if (str[i + 1] == 'i')
                ft_print_decimal(&result, va_arg(list, int));
            if (str[i + 1] == 'u')
                ft_print_unsigned_decimal(&result, va_arg(list, int));
            if (str[i + 1] == 'x')
                ft_print_num_hex_l(&result, va_arg(list, int), 1);
            if (str[i + 1] == 'X')
                ft_print_num_hex_l(&result, va_arg(list, int), 0);
            if (str[i + 1] == '%')
                result = ft_add_char(result, '%');
            i++;
        }
        else
            result = ft_add_char(result, str[i]);
        i++;
        va_end(list);
    }
    
    
    printf("%s\n", result);
    return (len);
}

int main()
{
    // int y = 8;
    // int c = 'g';
    int a = ft_printf("-->%% |%X| ;", -1237456);
    printf("-->|%%| ;");
   // printf("%zu\n", ptr);
}
