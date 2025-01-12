# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 16:19:02 by dlorenzo          #+#    #+#              #
#    Updated: 2025/01/12 21:39:38 by dlorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
AR = ar rcs
NAME = get_next_line.a
LFLAGS = -L. -l:get_next_line.a

# Files
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

# Bonus
#BONUS_SRC = 
#BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Test environment
TEST = test
TEST_SRC = test.c
TEST_BIN = $(TEST)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_BIN)

re: fclean all

# Bonus rule
#bonus: $(OBJ) $(BONUS_OBJ)
#	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)

# Test rule
test: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LFLAGS) -o $(TEST_BIN)