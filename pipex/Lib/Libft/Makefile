# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmeessen <vmeessen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 06:45:58 by vmeessen          #+#    #+#              #
#    Updated: 2025/04/02 06:45:58 by vmeessen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
        ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
OBJB = $(BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(NAME) $(OBJB)
	ar rcs $(NAME) $(OBJB)

all: $(NAME) $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

test: re
	gcc main.c -L. -lft -o my_program
	./my_program

re: fclean all

.PHONY: all bonus clean fclean re
