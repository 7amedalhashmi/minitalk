# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halhashm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 16:43:35 by halhashm          #+#    #+#              #
#    Updated: 2022/03/15 16:43:40 by halhashm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra

SRC = client.c server.c
OBJ = ${SRC:.c=.o}

all: $(SERVER) $(CLIENT)

$(SERVER):
		${CC} server.c -c
		${CC} ${FLAGS} -o server server.c

$(CLIENT):
		${CC} client.c -c
		${CC} -o client client.c

clean:
		${RM} ${SERVER} $(CLIENT)

fclean: clean
		${RM} ${OBJ}

re: fclean all
