# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 16:19:02 by dlorenzo          #+#    #+#              #
#    Updated: 2025/02/28 21:30:34 by dlorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
AR = ar rcs
NAME = get_next_line.a
BONUS_NAME = get_next_line_bonus.a
LFLAGS = -L. -l:get_next_line.a
BONUS_LFLAGS = -L. -l:get_next_line_bonus.a
NORM = norminette
NORMFLAGS = -R CheckForbiddenSourceHeader

# Files
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

# Bonus
BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Test environment
TEST = test
TEST_BONUS = test_bonus
TEST_SRC = test.c
TEST_BIN = $(TEST)
TEST_SRC_BONUS = test_bonus.c
TEST_BIN_BONUS = $(TEST_BONUS)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(BONUS_NAME): $(BONUS_OBJ)
	$(AR) $(BONUS_NAME) $(BONUS_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) $(TEST_BIN) $(TEST_BIN_BONUS)

re: fclean all

# Bonus rule
bonus: $(BONUS_NAME)

# Test rule
test: $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LFLAGS) -o $(TEST_BIN)

testbonus: $(BONUS_NAME) $(TEST_SRC_BONUS)
	$(CC) $(CFLAGS) $(TEST_SRC_BONUS) $(BONUS_LFLAGS) -o $(TEST_BIN_BONUS)

# Norminette
norm:
	$(NORM) $(NORMFLAGS) $(SRC) $(BONUS_SRC) get_next_line.h get_next_line_bonus.h
	
.PHONY: all clean fclean re bonus test