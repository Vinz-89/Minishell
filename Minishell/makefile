# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmeessen <vmeessen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 19:36:09 by vmeessen          #+#    #+#              #
#    Updated: 2025/05/02 19:36:09 by vmeessen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -g #-Wall -Wextra -Werror -g3 -fsanitize=address
# LFLAGS = -lmlx -lXext -lX11 -lm
READLINE = -lreadline

RM = rm -rf

SRCS = minishell.c
SRCS_UTILS = util.c split_utils.c builtin_util.c
SRCS_ = $(addprefix srcs/, $(SRCS)) $(addprefix srcs/utils/, $(SRCS_UTILS))

LIBDIR = Lib
LIB = lib.a

OBJ = $(SRCS_:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBDIR)/$(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBDIR)/$(LIB) $(READLINE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/$(LIB):
	$(MAKE) -C $(LIBDIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

test: $(NAME)
	@echo "---------------------------- $(NAME) ----------------------------"
	@./$(NAME)


re: fclean all
