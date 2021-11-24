# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lahammam <lahammam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 01:19:31 by lahammam          #+#    #+#              #
#    Updated: 2021/11/23 11:40:28 by lahammam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_BONUS = ft_printf_bonus.c bonus/ft_printf_utile1_bonus.c bonus/ft_printf_utile2_bonus.c bonus/ft_unsigned_itoa_bonus.c bonus/ft_convert_base_bonus.c
OBJES_BONUS = ${SRCS_BONUS:.c=.o}
SRCS = ft_printf.c mondatory/ft_printf_utile1.c mondatory/ft_printf_utile2.c mondatory/ft_unsigned_itoa.c mondatory/ft_convert_base.c
OBJES = ${SRCS:.c=.o}
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
bonus: ${LIBFT} ${OBJES_BONUS}
	${AR} ${NAME} ${OBJES_BONUS} ${LIBFT}/*.o
clean:
		${RM} ${OBJES} ${OBJES_BONUS} ${LIBFT}/*.o

fclean: clean
		${RM} ${NAME} ${LIBFT}/*.a

re:	fclean all

.PHONY: all clean fclean re bonus libft
