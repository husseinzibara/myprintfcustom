*This project has been created as part of the 42 curriculum by hzibara.*

## Description

Libft is a personal C library written entirely from scratch, with the goal of
understanding how each function works, its limitations, and how to use it
correctly. It contains:

- Re-implementations of standard libc functions (string, memory and character
  handling, e.g. `ft_strlen`, `ft_memcpy`, `ft_atoi`)
- Additional utility functions (`ft_substr`, `ft_strjoin`, `ft_strtrim`,
  `ft_split`, `ft_itoa`, `ft_putnbr_fd`, ...)
- Linked-list functions (`ft_lstnew`, `ft_lstadd_back`, `ft_lstmap`, ...)

## Instructions

- `make` or `make all`: compile the library and produce `libft.a`
- `make clean`: remove the object files
- `make fclean`: remove the object files and `libft.a`
- `make re`: run `fclean`, then rebuild

To use the library in a program, include `libft.h` and link against it:

    cc -Wall -Wextra -Werror main.c libft.a -I.

## Resources

- GeeksforGeeks (https://www.geeksforgeeks.org/): basic C tutorials
- Stack Overflow (https://stackoverflow.com/): specific technical issues
- Linux man pages: expected behavior and return values of libc functions
- Reddit (https://www.reddit.com/): code debugging and optimization discussions

### Use of AI

- Google Gemini: comparing different approaches to a problem and how each behaves.
- Claude: testing the compiled library with a custom test harness and ASan/UBSan,
  and diagnosing the failures it found.
