# -*- Makefile -*-

SRCS := 
OBJS := $(SRCS:.c=.o)
HEADER := libft.h
FLAGS := -Wall -Wextra -Werror
CC := cc
NAME:= libftprintf.a

.PHONY : clean fclean re all

all: $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ -I.
