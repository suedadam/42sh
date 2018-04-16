NAME = 42sh
STAT = deps/libft/libftprintf.a
CFLAGS += -Wall -Werror -Wextra -g -fsanitize=address
INCLUDES = -I deps/libft/inc \
		   -I src/ -I inc/
CC = gcc
LIBFT = libftprintf.a

################################################################################
# Source directories identifiers                                               #
################################################################################

SRCDIR_AST = src/ast_construction/srcs/

SRCDIR_EXEC = src/execution/
SRCDIR_EXEC_JOBS = job_control/
SRCDIR_EXEC_BUILTINS = builtins/
SRCDIR_EXEC_OPS = ops/
SRCDIR_EXEC_OPS_CHECKS = op_checks/
SRCDIR_EXEC_OPS_EXECS = op_execs/

SRCDIR_HISTORY = src/history/

SRCDIR_IPARSE = src/input_parser/

SRCDIR_MANAGER = src/manager/

SRCDIR_TERMIO = src/termio/
SRCDIR_TERMIO_AUTOCOMPLETE = autocomplete/
SRCDIR_TERMIO_BUFFER = buffer/
SRCDIR_TERMIO_CONTROL_CODES = control_codes/
SRCDIR_TERMIO_CURSOR = cursor/
SRCDIR_TERMIO_EDITING = editing/
SRCDIR_TERMIO_ESCAPE_SEQUENCES = escape_sequences/
SRCDIR_TERMIO_HANGING_BYTE = hanging_byte/
SRCDIR_TERMIO_LINEFEED = linefeed/
SRCDIR_TERMIO_MAIN_CONTROL = main_control/
SRCDIR_TERMIO_PROMPT = prompt/
SRCDIR_TERMIO_SCREEN = screen/

OBJSRC = $(patsubst %, %.o, $(addprefix $(SRCDIR_AST), $(SRC_AST)))
OBJSRC += $(patsubst %, %.o, $(addprefix $(SRCDIR_MANAGER), $(SRC_MANAGER)))
OBJSRC += $(patsubst %, %.o, $(addprefix $(SRCDIR_EXEC), $(SRC_EXEC)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_EXEC), $(SRCDIR_EXEC_BUILTINS)), \
		  $(SRC_EXEC_BUILTINS)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_EXEC), $(SRCDIR_EXEC_JOBS)), \
		  $(SRC_EXEC_JOBS)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_EXEC), \
		  $(addprefix $(SRCDIR_EXEC_OPS), $(SRCDIR_EXEC_OPS_CHECKS))), \
		  $(SRC_EXEC_OPS_CHECKS)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_EXEC), \
		  $(addprefix $(SRCDIR_EXEC_OPS), $(SRCDIR_EXEC_OPS_EXECS))), \
		  $(SRC_EXEC_OPS_EXECS)))
OBJSRC += $(patsubst %, %.o, $(addprefix $(SRCDIR_HISTORY), $(SRC_HISTORY)))
OBJSRC += $(patsubst %, %.o, $(addprefix $(SRCDIR_IPARSE), $(SRC_IPARSE)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_AUTOCOMPLETE)), \
		  $(SRC_TERMIO_AUTOCOMPLETE)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_BUFFER)), \
		  $(SRC_TERMIO_BUFFER)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_CONTROL_CODES)), \
		  $(SRC_TERMIO_CONTROL_CODES)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_CURSOR)), \
		  $(SRC_TERMIO_CURSOR)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_EDITING)), \
		  $(SRC_TERMIO_EDITING)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_ESCAPE_SEQUENCES)), \
		  $(SRC_TERMIO_ESCAPE_SEQUENCES)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_HANGING_BYTE)), \
		  $(SRC_TERMIO_HANGING_BYTE)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_LINEFEED)), \
		  $(SRC_TERMIO_LINEFEED)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_MAIN_CONTROL)), \
		  $(SRC_TERMIO_MAIN_CONTROL)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_PROMPT)), \
		  $(SRC_TERMIO_PROMPT)))
OBJSRC += $(patsubst %, %.o, $(addprefix \
		  $(addprefix $(SRCDIR_TERMIO), $(SRCDIR_TERMIO_SCREEN)), \
		  $(SRC_TERMIO_SCREEN)))

################################################################################
# COLOR                                                                        #
################################################################################

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RES = \033[0m

################################################################################
# AST SOURCE FILES                                                             #
################################################################################

SRC_AST =	\
          ast \
          ast_free_utils \
          new_ast_utils \
          utils

################################################################################
# EXECUTION SOURCE FILES                                                       #
################################################################################

SRC_MANAGER = \
			manager

SRC_EXEC =	\
			execution \
			redirection \
			builders \
			utils \
			runners \
			helpers 

SRC_EXEC_BUILTINS = \
			env \
			handler \
			echo \
			cd \
			fg \
			env_utils \
			history 

SRC_EXEC_OPS_CHECKS =	\
            op_and \
            op_or \
            op_pipe

SRC_EXEC_JOBS =	\
            suspend

SRC_EXEC_OPS_EXECS =	\
            op_and \
            op_or \
            op_pipe

################################################################################
# EXECUTION SOURCE FILES                                                       #
################################################################################

SRC_HISTORY =	\
			history \
			history_keyboard_actions \
			history_utils

################################################################################
# PARSER SOURCE FILES                                                          #
################################################################################

SRC_IPARSE =	\
        add_token \
        is_op \
        is_op_append \
        is_quote \
        is_semicolon \
        is_whitespace \
        is_word \
        parser \
        quoting \
        strappend \
		command_sub \
		sh_strcat \
		subshell \
		btick


################################################################################
# TERMIO SOURCE FILES                                                          #
################################################################################

# AUTOCOMPLETE
SRC_TERMIO_AUTOCOMPLETE =	\
					autocomplete \
					autocomplete_manager \
					autofind_pathnames \
					buildir_names \
					check_possible_dir \
					concat_path \
					count_word \
					del_paths \
					gather_paths \
					id_add_name \
					trie_rebuild \
					trie_utils

# BUFFER
SRC_TERMIO_BUFFER =	\
					init_buffer \
					reprint_buffer \
					reset_buffer \
					resize_buffer \
					update_buffer

# CONTROL CHARACTERS
SRC_TERMIO_CONTROL_CODES =	\
					control_a \
					control_c \
					control_e \
					control_l \
					control_h \
					control_j \
					control_k \
					control_m \
					control_o \
					control_u \
					control_v \
					control_w \
					control_y \
					control_newline \
					control_execute

# CURSOR
SRC_TERMIO_CURSOR = \
					cursor_actions \
					cursor_jump \
					cursor_locate \
					cursor_move \
					cursor_position \
					cursor_visibility

# EDITING

SRC_TERMIO_EDITING = \
					cut_line \
					cut_word \
					yank

# ESCAPE SEQUENCES
SRC_TERMIO_ESCAPE_SEQUENCES =	\
					multibyte_dispatch \
					ft_linemove \
					ft_shift \
					ft_alt \
					ft_backspace \
					ft_delete \
					ft_history \
					ft_page \
					screen_scroll

# HANGING BYTE
SRC_TERMIO_HANGING_BYTE =	\
					curly_mode \
					hanging_byte \
					hanging_delete \
					paren_mode \
					quote_mode

# LINEFEED
SRC_TERMIO_LINEFEED =	\
					linefeed

# MAIN CONTROL
SRC_TERMIO_MAIN_CONTROL =	\
					change_terminal \
					error \
					jump_defs \
					keys_handler \
					main \
					my_putchar \
					read_loop \
					regular_text \
					set_signal

# PROMPT
SRC_TERMIO_PROMPT =	\
					drop_prompt \
					new_prompt \
					reset_prompt

# SCREEN
SRC_TERMIO_SCREEN =	\
					count_lines \
					del_lines \
					update_screen \
					get_window_size \
					clear_below

################################################################################
# RULES                                                                        #
################################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJSRC)
	@ echo "$(YELLOW)Building static library...$(RES)"
	@ echo "$(YELLOW)Compiling program$(RES)"
	$(CC) $(CFLAGS) -L deps/libft -lftprintf -ltermcap $(OBJSRC) -o $(NAME)
	# $(CC) $(CFLAGS) $(MALLOC_PATH) -L deps/libft -lftprintf -ltermcap $(OBJSRC) -o $(NAME)
	# install_name_tool -change $(MALLOC) $(MALLOC_PATH) $(NAME)
	@ echo "$(GREEN)$(NAME) binary ready$(RES)"


$(LIBFT):
	#@git submodule init
	#@git submodule update
	make -C deps/libft

%.o: %.c
	@ echo "$(YELLOW)Compiling $<...$(RES)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@/bin/rm -f $(OBJSRC)
	make -C deps/libft clean
	@ echo "$(RED)Cleaning folders of object files...$(RES)"

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(STAT)
	@ echo "$(RED)Removing library file and binary...$(RES)"

re: fclean all
	@ echo "$(GREEN)Binary Remade$(RES)"
