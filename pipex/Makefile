# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmeessen <vmeessen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 06:41:44 by vmeessen          #+#    #+#              #
#    Updated: 2025/04/02 06:41:44 by vmeessen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = pipex.c pipex_utils.c
OBJ = $(SRC:.c=.o)

INFILE = infile
OUTFILE = outfile

LIBFT_PATH = Lib/libft
LIBFT = $(LIBFT_PATH)/Libft.a

INCLUDE = -L ./Libft -lft

all: $(LIBFT) $(NAME)

# valgrind --leak-check=full --trace-children=yes --track-fds=yes

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
