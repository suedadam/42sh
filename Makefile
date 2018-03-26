PROGRAM = fileio
NAME = lib/libftls.a 
CFLAGS += -Wall -Werror -Wextra -g #-fsanitize=address
INCLUDES = -I lib/ -I lib/ft_printf -I src/ -I inc/ 
CC = gcc
OBJSRC = $(patsubst %, %.o, $(SRC))
OBJINC = $(patsubst %, %.o, $(INC))

# LEMIN SOURCE
SRC += src/test
SRC += src/error
SRC += src/exec_handlers
SRC += src/cursor_moves
SRC += src/multibyte_dispatch

# GENERAL LIBFT FUNCTIONS
INC += lib/ft_strlen
INC += lib/ft_memalloc
INC += lib/ft_strcpy
INC += lib/ft_bzero
INC += lib/ft_isalpha
INC += lib/ft_isdigit
INC += lib/ft_memdel
INC += lib/ft_memset
INC += lib/ft_strncpy
INC += lib/ft_strcat
INC += lib/ft_strnew
INC += lib/ft_strsplit
INC += lib/ft_strsub
INC += lib/ft_strcmp
INC += lib/ft_memcpy
INC += lib/ft_memmove
INC += lib/ft_queue
INC += lib/ft_queue_util
INC += lib/ft_dblistnew
INC += lib/ft_mergesort
INC += lib/ft_strdup
INC += lib/ft_strchr
INC += lib/ft_numlen
INC += lib/ft_atoi_base
INC += lib/ft_strnstr
INC += lib/ft_strnchr
INC += lib/ft_strchr
INC += lib/ft_nlookup
INC += lib/ft_atoi
INC += lib/ft_lstadd
INC += lib/ft_isalnum
INC += lib/ft_strnequ
INC += lib/ft_strncmp
INC += lib/ft_fifoqueue
INC += lib/ft_error
INC += lib/ft_strequ

# FTPRINTF
INC += lib/ft_printf/conversion_diou
INC += lib/ft_printf/dispatcher
INC += lib/ft_printf/printflags
INC += lib/ft_printf/conversion_sc
INC += lib/ft_printf/storeflags
INC += lib/ft_printf/conversion_xp
INC += lib/ft_printf/misc
INC += lib/ft_printf/ulitobase

all: $(NAME)

$(NAME): $(OBJINC) $(OBJSRC)
	@ echo "Building static library..."
	@ ar -rcs $(NAME) $(OBJINC)
	@ echo "Compiling $(PROGRAM) program"
	@ $(CC) $(CFLAGS) -L lib/ -lftls -ltermcap $(OBJSRC) -o $(PROGRAM)

%.o: %.c
#	@ echo "Compiling $<..."
	@ $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ /bin/rm -f $(OBJSRC)
	@ /bin/rm -f $(OBJINC)
	@ echo "Cleaning folders of object files..."

fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(PROGRAM)
	@ echo "Removing library file and binary..."

re: fclean all
	@ echo "Program Remade"
