# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 11:04:57 by qurobert          #+#    #+#              #
#    Updated: 2021/03/02 15:19:13 by qurobert         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = 		libasm.a
FILES =		ft_write.s ft_read.s ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s
INC_FILES = libasm.h
INC_PATH = ./includes/
SRC_PATH = ./srcs/
INC 	= 	$(addprefix $(INC_PATH),$(INC_FILES))
SRC = 		$(addprefix $(SRC_PATH),$(FILES))
CC = 		nasm
OBJ = 		$(SRC:.s=.o)
FLAGS = 	-f macho64

all: 		$(NAME)

$(NAME):	$(OBJ)
			@ar rcs $(NAME) $(OBJ)

%.o: %.s 	$(INC)
			@$(CC) $(FLAGS) $< -o $(<:.s=.o) -I $(INC_PATH)
			@printf '\033[32m [✓] %s\n\033[0m'  "$(notdir $<)"

clean:
			@rm -f $(OBJ)
			@printf '\033[32m [✓] clean%s\n\033[0m'

fclean:		clean
			@printf '\033[32m [✓] fclean%s\n\033[0m'
			@rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re lib