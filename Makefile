# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehong <jehong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/03 15:58:24 by jehong            #+#    #+#              #
#    Updated: 2020/04/03 16:08:41 by jehong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = factorization
SRCS = ./factorization.c
OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o: ${SRCS}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLGAS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: re fclean clean all