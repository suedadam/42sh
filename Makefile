#!/usr/bin/make -f

################################################################################
# SETTINGS                                                                     #
################################################################################

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
INC = -I inc
SRC_DIR = src
SRC = \
	atoi\
	itoa\
	lstnew\
	memalloc\
	memccpy\
	memchr\
	memcmp\
	memcpy\
	memdel\
	memmove\
	memset\
	mchain\
	mladd\
	mlalloc\
	mlappend\
	mlarray\
	mldel\
	mlfind\
	mlpop\
	mlremove\
	mlrev\
	mlxfer\
	putchar\
	putchar_fd\
	putendl\
	putendl_fd\
	putnbr\
	putnbr_fd\
	putstr\
	putstr_fd\
	queue\
	stpcpy\
	stpncpy\
	strcapitalize\
	strcat\
	strchr\
	strclr\
	strcmp\
	strcpy\
	strdel\
	strdup\
	strequ\
	strjoin\
	strlcat\
	strlcpy\
	strlen\
	strlowcase\
	strncat\
	strncmp\
	strncpy\
	strndup\
	strnequ\
	strnew\
	strnlen\
	strnstr\
	strrchr\
	strrev\
	strstr\
	strsub\
	strtrim\
	strupcase
OBJ_DIR = $(SRC_DIR)/obj
OBJ = $(patsubst %, $(OBJ_DIR)/ft_%.o, $(SRC))

################################################################################
# COLORS                                                                       #
################################################################################

NC = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m

################################################################################
# RULES                                                                        #
################################################################################

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $(OBJ)
	@echo "$(GREEN)DONE$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed$(NC)"

re: fclean all
