# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 01:19:31 by lahammam          #+#    #+#              #
#    Updated: 2021/11/24 19:44:17 by lahammam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_csp.c ft_printf_dux.c ft_unsigned_itoa.c ft_convert_base.c \
		ft_flags1.c ft_flags2.c ft_printf_utile1.c
OBJES = ${SRCS:.c=.o}
# SRCS = ft_printf.c mondatory/ft_printf_utile1.c mondatory/ft_printf_utile2.c mondatory/ft_unsigned_itoa.c mondatory/ft_convert_base.c
# OBJES = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf
LIBFT = libft

%.o : %.c
	   ${CC} ${CFLAGS} -c $< -o $@

all: ${LIBFT} ${NAME} 

${NAME} : ${OBJES} 
		${AR} $@ ${OBJES} ${LIBFT}/*.o

${LIBFT} :
	${MAKE} -C ${LIBFT}
bonus: all
	
clean:
		${RM} ${OBJES}  ${LIBFT}/*.o

fclean: clean
		${RM} ${NAME} ${LIBFT}/*.a

re:	fclean all

.PHONY: all clean fclean re bonus libft
