# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 12:48:11 by dtomchys          #+#    #+#              #
#    Updated: 2018/02/27 12:48:13 by dtomchys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dtomchys.filler
BONUS = collors
CC = gcc -Wall -Werror -Wextra -g3
RM = rm -f
HD = filler.h
MFLIB = ./libft
SRC = ft_filler.c ft_set_figure.c ft_tools.c ft_find_valis_points.c\
ft_find_opponent_points.c\

BONUS_SRC = ft_mega_visualizer.c\

OBJ_B = $(BONUS_SRC:.c=.o)
OBJ = $(SRC_C:.c=.o) $(SRC:.c=.o)

all: $(NAME) $(BONUS)

OBJ: $(SRC) filler.h
	$(CC) $(SRC) $(HD) -c

OBJ_B: $(BONUS_SRC) filler.h
	$(CC) $(BONUS_SRC) $(HD) -c

$(NAME):  $(OBJ) $(HD)
	make -C $(MFLIB)
	$(CC) -o $(NAME) $(OBJ) -I.$(HD) libft/libft.a

$(BONUS): $(OBJ_B) $(HD)
	$(CC) -o $(BONUS) $(OBJ_B) -I.$(HD) libft/libft.a 

clean:
	make clean -C $(MFLIB)
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) $(BONUS) libft.a

re: fclean all

.PHONY: clean fclean
