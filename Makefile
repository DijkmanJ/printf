# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jdijkman <jdijkman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/23 15:48:35 by jdijkman      #+#    #+#                  #
#    Updated: 2024/01/08 10:44:29 by jdijkman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_argfuncs.c ft_printf.c

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

RM = rm -rf

CFLAGS = -Werror -Wall -Wextra -g

OBJ = $(SRC:%.c=%.o)

all:				$(NAME)

$(NAME):			$(OBJ) $(LIBFT)
					cp $(LIBFT) $(NAME)
					ar -rcs $(NAME) $(OBJ)

$(LIBFT):
					make -C $(LIBFT_PATH) all

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re: fclean all

.PHONY:				all bonus clean fclean re libft main