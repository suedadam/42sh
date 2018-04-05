NAME = 42sh
STAT = lib/libft.a
CFLAGS += -Wall -Werror -Wextra -g -fsanitize=address
INCLUDES = -I lib/ -I lib/ft_printf -I src/ -I inc/
CC = gcc
SRCDIR = src/
LIBDIR = lib/
OBJSRC = $(patsubst %, %.o, $(addprefix $(SRCDIR),$(SRC)))
OBJLIB = $(patsubst %, %.o, $(addprefix $(LIBDIR), $(LIB)))
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RES = \033[0m


# FILEIO SOURCE
SRC += backslash_char
SRC += buffer_utils
SRC += carriage_return
SRC += change_terminal
SRC += cursor_moves
SRC += exec_handlers
SRC += error
SRC += history
SRC += keys_handler
SRC += main
SRC += my_putchar
SRC += prompt_utils
SRC += read_loop
SRC += set_signal
SRC += scrn_info
SRC += utils
SRC += update_screen_utils
SRC += quote_mode
SRC += screen_scroll
SRC += cursor_actions
SRC += cursor_visibility
SRC += init_tokens 
SRC += cursor_navigation 

# CONTROL CHARACTERS
SRC += control_codes/control_dispatch
SRC += control_codes/control_a
SRC += control_codes/control_c
SRC += control_codes/control_e
SRC += control_codes/control_l
SRC += control_codes/control_g
SRC += control_codes/control_h
SRC += control_codes/control_j
SRC += control_codes/control_m
SRC += control_codes/control_o
SRC += control_codes/control_u
SRC += control_codes/control_v
SRC += control_codes/control_w
SRC += control_codes/control_newline
SRC += control_codes/control_execute
SRC += control_codes/ft_backspace
SRC += control_codes/ft_delete

# ESCAPE SEQUENCES
SRC += escape_sequences/multibyte_dispatch
SRC += escape_sequences/ft_linemove
SRC += escape_sequences/ft_shift

# GENERAL LIBFT FUNCTIONS
LIB += ft_strlen
LIB += ft_memalloc
LIB += ft_strcpy
LIB += ft_bzero
LIB += ft_isalpha
LIB += ft_isdigit
LIB += ft_memdel
LIB += ft_memset
LIB += ft_strncpy
LIB += ft_strcat
LIB += ft_strnew
LIB += ft_strsplit
LIB += ft_strsub
LIB += ft_strcmp
LIB += ft_memcpy
LIB += ft_memmove
LIB += ft_queue
LIB += ft_queue_util
LIB += ft_dblistnew
LIB += ft_mergesort
LIB += ft_strdup
LIB += ft_strchr
LIB += ft_numlen
LIB += ft_atoi_base
LIB += ft_strnstr
LIB += ft_strnchr
LIB += ft_strchr
LIB += ft_nlookup
LIB += ft_atoi
LIB += ft_lstadd
LIB += ft_isalnum
LIB += ft_strnequ
LIB += ft_strncmp
LIB += ft_fifoqueue
LIB += ft_error
LIB += ft_strequ
LIB += ft_putchar_fd
LIB += ft_putstr_fd
LIB += ft_putendl_fd


# FTPRINTF
LIB += ft_printf/conversion_diou
LIB += ft_printf/dispatcher
LIB += ft_printf/printflags
LIB += ft_printf/conversion_sc
LIB += ft_printf/storeflags
LIB += ft_printf/conversion_xp
LIB += ft_printf/misc
LIB += ft_printf/ulitobase

all: $(NAME)

$(NAME): $(OBJLIB) $(OBJSRC)
	@ echo "$(YELLOW)Building static library...$(RES)"
	ar -rcs $(STAT) $(OBJLIB)
	@ echo "$(YELLOW)Compiling ftls program$(RES)"
	$(CC) $(CFLAGS) -L lib/ -lft -ltermcap $(OBJSRC) -o $(NAME)
	@ echo "$(GREEN)$(NAME) binary ready$(RES)"

%.o: %.c
	@ echo "$(YELLOW)Compiling $<...$(RES)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ /bin/rm -f $(OBJSRC)
	@ /bin/rm -f $(OBJLIB)
	@ echo "$(RED)Cleaning folders of object files...$(RES)"

fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(STAT)
	@ echo "$(RED)Removing library file and binary...$(RES)"

re: fclean all
	@ echo "$(GREEN)Binary Remade$(RES)"
