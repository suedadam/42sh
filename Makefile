#!/usr/bin/make -f

################################################################################
# SETTINGS                                                                     #
################################################################################

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

42SH = 42sh
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3
OBJFLAGS = -Wall -Werror -Wextra -O3 -c
LIBFT = deps/libft/libft.a
MALLOC = deps/malloc/libft_malloc_${HOSTTYPE}.so
42SH_MANAGER_SRCDIR = manager
42SH_EXECUTION_SRCDIR = execution
42SH_ASTCONSTRUCTION_SRCDIR = ast_construction
42SH_MANAGER_SRC = \
	manager 
42SH_EXECUTION_SRC = \
	execution \
	redirection \
	ops/op_checks/op_and \
	ops/op_checks/op_or \
	ops/op_checks/op_pipe \
	ops/op_execs/op_and \
	ops/op_execs/op_or \
	ops/op_execs/op_pipe \
	builtins/env \
	builtins/handler
42SH_ASTCONSTRUCTION_SRC = \
	srcs/ast \
	srcs/ast_free_utils \
	srcs/debugging \
	srcs/new_ast_utils \
	srcs/utils 
42SH_MANAGER_OBJ = $(patsubst %, obj/%.o, $(42SH_MANAGER_SRC))
42SH_EXECUTION_OBJ = $(patsubst %, obj/%.o, $(42SH_EXECUTION_SRC))
42SH_ASTCONSTRUCTION_OBJ = $(patsubst %, obj/%.o, $(42SH_ASTCONSTRUCTION_SRC))
42SH_INC = -I includes -I deps/

################################################################################
# COLORS                                                                       #
################################################################################

NC = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
BLUE = \033[1;36m

################################################################################
# RULES                                                                        #
################################################################################

all: $(42SH)

DEBUG: $(LIBFT) $(42SH_MANAGER_OBJ) $(42SH_EXECUTION_OBJ) $(42SH_ASTCONSTRUCTION_OBJ)
	@printf "$(YELLOW)%-50s$(NC)" "Building $@... "
	$(CC) $(CFLAGS) -g -fsanitize=address $(LIBFT) $(42SH_MANAGER_OBJ) $(42SH_EXECUTION_OBJ) $(42SH_ASTCONSTRUCTION_OBJ) $(42SH_INC) ast_construction/main.c -o $@
	@echo "$(GREEN)DONE$(NC)"

$(42SH): $(LIBFT) $(MALLOC) $(42SH_MANAGER_OBJ) $(42SH_EXECUTION_OBJ) $(42SH_ASTCONSTRUCTION_OBJ)
	@printf "$(YELLOW)%-50s$(NC)" "Building $@... "
	@$(CC) $(CFLAGS) $(LIBFT) $(MALLOC) $(42SH_MANAGER_OBJ) $(42SH_EXECUTION_OBJ) $(42SH_ASTCONSTRUCTION_OBJ) $(42SH_INC) ast_construction/main.c -o $@
	@echo "$(GREEN)DONE$(NC)"
	@install_name_tool -change libft_malloc_x86_64_Darwin.so $(PWD)/deps/malloc/libft_malloc_x86_64_Darwin.so 42sh

obj/%.o: $(42SH_EXECUTION_SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)%-50s$(NC)" "Building $@... "
	@$(CC) $(OBJFLAGS) $(42SH_INC) -c $< -o $@

obj/%.o: $(42SH_ASTCONSTRUCTION_SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)%-50s$(NC)" "Building $@... "
	@$(CC) $(OBJFLAGS) $(42SH_INC) -c $< -o $@


obj/%.o: $(42SH_MANAGER_SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)%-50s$(NC)" "Building $@... "
	@$(CC) $(OBJFLAGS) $(42SH_INC) -c $< -o $@

$(MALLOC):
	@printf "$(YELLOW)%-50s$(NC)" "Building $@... "
	@make -C deps/malloc

$(LIBFT):
	@printf "$(YELLOW)%-50s$(NC)" "Building $@... "
	@make -C deps/libft

clean:
	@rm -rf obj
	@make -C deps/libft clean
	@make -C deps/malloc fclean
	@echo "$(RED)Object files removed$(NC)"

fclean: clean
	@make -C deps/libft fclean
	@make -C deps/malloc fclean
	@rm -rf $(42SH) DEBUG DEBUG.dSYM
	@echo "$(BLUE) $(42SH) removed$(NC)"

re: fclean all