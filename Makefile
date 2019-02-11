# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtroll <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 23:15:17 by rtroll            #+#    #+#              #
#    Updated: 2018/12/15 16:50:29 by rtroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
	  ft_get_tetro.c\
	  ft_make_tetro.c\
	  list_stuff.c\
	  map_stuff.c\
	  solve.c

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH), $(SRC))

INC = -I includes

LIBFT = src/libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT) 

$(OBJ): $(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC_POS) $(INC)

$(LIBFT):
	@make -C ./src/libft/

clean:
	@rm -f $(OBJ)
	@make clean -C ./src/libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./src/libft

re: fclean all
