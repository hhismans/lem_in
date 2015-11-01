# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/26 11:52:39 by hhismans          #+#    #+#              #
#    Updated: 2015/10/28 20:45:40 by hhismans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c \
	  src/node.c \
	  src/edge.c \
	  src/tolibft.c \
	  src/djikstra.c\
	  src/path.c \
	  src/ants.c
FLAG = -Wall -Werror -Wextra
INCLUDES = -I./includes -I./libft -I.

all :
	gcc $(FLAG) $(INCLUDES) $(SRC) libft.a
