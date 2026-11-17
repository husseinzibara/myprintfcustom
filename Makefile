# -*- Makefile -*-

SRCS := ft_printf.c ft_printf_flags.c ft_flag_functions.c ft_itobase.c ft_printf_char_printers.c ft_printf_num_printers.c ft_printf_precision.c
OBJS := $(SRCS:.c=.o)
HEADER := libft_printf.h
LIBFT := libft/libft.a
FLAGS := -Wall -Wextra -Werror
CC := cc
NAME:= libftprintf.a

.PHONY : clean fclean re all

all: $(NAME)

clean :
	rm -f $(OBJS)
	make -C libft clean

fclean :
	make clean
	make -C libft fclean
	rm -f $(NAME)

re :
	make fclean
	make all

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ -I.
