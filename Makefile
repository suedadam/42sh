# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: satkins <satkins@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 14:05:53 by satkins           #+#    #+#              #
#    Updated: 2018/04/13 18:43:08 by asyed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/ft_atoi.c \
		  libft/ft_bzero.c \
		  libft/ft_isalnum.c \
		  libft/ft_isalpha.c \
		  libft/ft_isascii.c \
		  libft/ft_isdigit.c \
		  libft/ft_isprint.c \
		  libft/ft_memccpy.c \
		  libft/ft_memchr.c \
		  libft/ft_memcmp.c \
		  libft/ft_memcpy.c \
		  libft/ft_memmove.c \
		  libft/ft_memset.c \
		  libft/ft_strcat.c \
		  libft/ft_strchr.c \
		  libft/ft_strcmp.c \
		  libft/ft_strcpy.c \
		  libft/ft_strdup.c \
		  libft/ft_strlcat.c \
		  libft/ft_strlen.c \
		  libft/ft_strncat.c \
		  libft/ft_strncmp.c \
		  libft/ft_strncpy.c \
		  libft/ft_strnstr.c \
		  libft/ft_strrchr.c \
		  libft/ft_strstr.c \
		  libft/ft_tolower.c \
		  libft/ft_toupper.c \
		  libft/ft_memalloc.c \
		  libft/ft_memdel.c \
		  libft/ft_strnew.c \
		  libft/ft_strdel.c \
		  libft/ft_strclr.c \
		  libft/ft_striter.c \
		  libft/ft_striteri.c \
		  libft/ft_strmap.c \
		  libft/ft_strmapi.c \
		  libft/ft_strequ.c \
		  libft/ft_strnequ.c \
		  libft/ft_strsub.c \
		  libft/ft_strjoin.c \
		  libft/ft_strtrim.c \
		  libft/ft_strsplit.c \
		  libft/ft_itoa.c \
		  libft/ft_putchar.c \
		  libft/ft_putstr.c \
		  libft/ft_putendl.c \
		  libft/ft_putnbr.c \
		  libft/ft_putchar_fd.c \
		  libft/ft_putstr_fd.c \
		  libft/ft_putendl_fd.c \
		  libft/ft_putnbr_fd.c  \
		  libft/ft_strnjoin.c \
		  libft/get_next_line.c \
		  libft/ft_putnstr.c \
		  libft/ft_putnstr_fd.c \
		  libft/ft_handle_error.c \
		  libft/ft_toupper_str.c \
		  libft/ft_ullitoa_base.c \
		  libft/pqueue.c \
		  libft/queue.c \
		  libft/ft_lstnew.c \
		  libft/ft_splitwhitespace.c \
		  libft/stack.c 

PRINTF = printf/ft_printf.c \
		 printf/ft_printf_fd.c \
		 printf/argument_handlers.c \
		 printf/printer.c \
		 printf/num_format.c \
		 printf/hex_print.c \
		 printf/int_printer.c \
		 printf/uint_printer.c \
		 printf/oct_printer.c \
		 printf/ptr_printer.c \
		 printf/wstr_print.c \
		 printf/wchar_print.c \
		 printf/char_print.c

SRCS = $(LIBFT) $(PRINTF)

EXE = exe

MAIN = main.c

LIB = libft/libft.a

HEADER = inc

CC = gcc

FLAGS = -Wall -Wextra -Werror

CFLAGS = -Wall -Wextra -Werror -c

TARG = $(SRCS:.c=.o)

LIBTARG = $(LIBFT:.c=.o)
		

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) -I$(HEADER) $^ && mv *.o libft/
	$(CC) $(CFLAGS) -I$(HEADER) $(PRINTF) && mv *.o 'printf/'
	@ar rc $(NAME) $(TARG)


clean:
	@/bin/rm -f $(TARG)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

