NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_DIR	= libft

SRCS		= ft_printf.c ft_printf_utils.c ft_itobase.c
BONUS_SRCS	= ft_printf_bonus.c ft_printf_flags_bonus.c ft_flag_functions_bonus.c ft_itobase_bonus.c ft_printf_char_printers_bonus.c ft_printf_num_printers_bonus.c ft_printf_precision_bonus.c
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
HEADER = ft_printf.h
BONUS_HEADER = ft_printf_bonus.h

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)
	rm -f $(BONUS_OBJS) .bonus


bonus: .bonus

.bonus: $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(BONUS_OBJS)
	rm -f $(OBJS)
	touch .bonus

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS): %.o: %.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) .bonus
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
