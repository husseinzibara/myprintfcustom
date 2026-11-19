*This project has been created as part of the 42 curriculum by hzibara.*

## Description

**ft_printf** is a re-implementation of the C library function `printf()`. The goal is to learn how variadic functions work in C (`stdarg.h`) and how to design code that is structured and easy to extend.

The project builds a static library, `libftprintf.a`, that exposes one function:

    int ft_printf(const char *, ...);

It returns the number of characters printed, like the original. No buffering is implemented: output goes straight to standard output with `write` (directly, or through libft's `ft_putstr_fd`).

### Mandatory part

Supported conversions: `c s p d i u x X %`.

| Conversion | Output |
|------------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` when the pointer is NULL) |
| `%p` | a `void *` in hexadecimal with a `0x` prefix (`(nil)` when NULL, as glibc does on Linux) |
| `%d` `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` `%X` | an unsigned integer in lowercase / uppercase hexadecimal |
| `%%` | a percent sign |

### Bonus part

- Flags `-`, `0` and `.` (precision), plus the minimum field width, for all conversions, in any combination. `*` is accepted for both width and precision.
- Flags `#`, `+` and space.

Each conversion only honours the flags that make sense for it and ignores the others, as the original printf does:

| Conversion | Flags honoured | Precision means |
|------------|----------------|-----------------|
| `c` | `-` | not used |
| `s` | `-` | maximum number of characters printed |
| `d` `i` | `-` `+` space `0` | minimum number of digits |
| `u` | `-` `0` | minimum number of digits |
| `x` `X` | `-` `0` `#` (`#` is ignored for the value 0) | minimum number of digits |
| `p` | `-` `0` | not used |

Known differences from glibc, all of which are undefined behaviour in the C standard: `%p` ignores `+`, space and precision (glibc adds a sign or zero-pads), a width on `%%` is applied (glibc prints a bare `%`), and a lone `%` at the end of the format or an unknown conversion prints nothing.

## Instructions

The project is built with `cc -Wall -Wextra -Werror` and uses your own libft, which must be present in a `libft/` folder at the root of the repository, with its own Makefile. The main Makefile builds libft first, then copies it to `libftprintf.a` and adds this project's objects with `ar rcs`.

| Command | Result |
|---------|--------|
| `make` | builds the mandatory `libftprintf.a` |
| `make bonus` | builds the bonus `libftprintf.a` (replaces the mandatory one) |
| `make clean` | removes object files (and libft's) |
| `make fclean` | also removes `libftprintf.a` and the bonus marker |
| `make re` | `fclean`, then `make` (mandatory version) |

To use the library, include `ft_printf.h` (or `ft_printf_bonus.h` for the bonus build) in your source file and link with `-L. -lftprintf`.

The Makefile never relinks when nothing changed. Switching between `make` and `make bonus` rebuilds the right objects, so the archive always contains exactly one `ft_printf`. This works because the mandatory and bonus builds delete each other's object files, and a hidden `.bonus` marker file records that the bonus build is finished.

### File layout

| File | Role |
|------|------|
| `ft_printf.c`, `ft_printf.h` | mandatory: format loop and conversion dispatch |
| `ft_printf_utils.c` | mandatory: the printers for each conversion |
| `ft_itobase.c` | mandatory: unsigned number to string in any base |
| `ft_printf_bonus.c`, `ft_printf_bonus.h` | bonus: format parsing and dispatch |
| `ft_printf_flags_bonus.c` | bonus: flag table, flag filtering, flag application |
| `ft_flag_functions_bonus.c` | bonus: one function per flag |
| `ft_printf_precision_bonus.c` | bonus: precision handling |
| `ft_printf_char_printers_bonus.c`, `ft_printf_num_printers_bonus.c` | bonus: the printers for each conversion |
| `ft_itobase_bonus.c` | bonus: copy of the base converter |

## Algorithm and data structures

### Mandatory version

**Format loop.** `ft_printf` walks the format string once. Ordinary characters are written immediately. On a `%` followed by another character, it calls a dispatcher that picks the printer for that conversion. Every printer prints its output and returns the number of characters written, and the loop adds these up into the return value.

**Passing the arguments.** The `va_list` is passed to the dispatcher *by pointer*. If it were passed by value, the arguments consumed inside the dispatcher would not be consumed in the main loop, and the next conversion would read the wrong argument. Passing a pointer keeps one shared position in the argument list.

**Numbers as strings.** `%d`/`%i` use libft's `ft_itoa`. `%u`, `%x`, `%X` and `%p` use `ft_itobase`, which converts an `unsigned long` to a string in any base. It first validates the base (at least two characters, no duplicates, no `+`, `-` or whitespace), then fills a buffer of 65 bytes, which is enough for 64 binary digits plus the terminator. The digits are produced by recursion: the function recurses on `n / base` first, so the most significant digit is written first without having to reverse the result afterwards. Values are widened to `unsigned long` so that pointers fit.

**Why this design.** Turning every number into a string means the length of the output is simply the string length, so the return value is easy to compute and the same base converter serves four conversions. The cost is one allocation per number, which is freed right after printing.

### Bonus version

The bonus is designed around one idea: build the text of the conversion as a string, then *transform* that string step by step until it is ready to print. Flags, precision and width then become small independent transformations instead of special cases inside each printer.

**Parsing.** For each `%`, three things are read in order and stored in a small struct, `t_spec`, which holds the width, the precision (`-1` meaning "none") and a short string of the flag characters seen:
1. the flags (`- + space # 0`, in any order),
2. the width, either digits or `*`. A negative `*` width is turned into the `-` flag with the absolute value as width,
3. the precision after a `.`, either digits or `*`. A bare `.` means precision 0, and a negative `*` precision means "no precision".

**The printer pipeline.** Each printer does the same steps:
1. Build the base string (`ft_itoa`, `ft_itobase`, or a copy of the string argument).
2. Remove the flags the conversion ignores (`filter_mods`).
3. Apply precision: for numbers, pad with zeros up to the minimum number of digits (the sign does not count, and the value 0 with precision 0 prints nothing); for strings, cut to the maximum length. Once an integer has a precision, the `0` flag is dropped.
4. Apply the flags and width (`apply_flags`).
5. Print and free.

**The flag table.** The flags are stored in an array of structs pairing a flag character with a function pointer, ending with a sentinel entry. The array is ordered `#`, `+`, space, `0`, `-`, and `apply_flags` walks it in that fixed order and calls the function for every flag present. The order matters:
- prefix and sign first (`0x`, `+`, space), because zero padding must go *between* the sign or prefix and the digits (as in `+00042` or `0x00ff`),
- zero fill next, which skips over the sign and prefix,
- left justification last, and if `-` is absent a default right-justify pads with spaces on the left.

Because the table is walked in its own order, the result does not depend on the order the user typed the flags in. `+` and space together give `+`, because the space function does nothing if a sign is already present, and `0` is skipped whenever `-` is present.

**Why a table of function pointers.** It avoids long chains of `if` statements in every printer, keeps each flag in its own small function, and makes adding a flag a matter of writing one function and one table entry. This follows the subject's advice that extensible code is the key. The trade-off is extra allocations (each step builds a new string with `ft_strjoin`), which is acceptable for printing and keeps every step simple and independently testable.

**Special cases.**
- `%c` with the value 0 cannot be stored in a C string, so it has its own path that writes the padding and the NUL byte directly and returns the right count.
- `%X` is built as lowercase hex and converted to uppercase *after* the flags are applied, so `0x` correctly becomes `0X`.
- `%s` with NULL prints `(null)`, except when a precision under 6 is given, where it prints nothing (as glibc does). `%p` with NULL prints `(nil)`.

## Testing

The implementation was compared against the system `printf` using a throw-away test program (not part of the repository) covering several thousand combinations of conversions, flags, widths and precisions, including `INT_MIN`, `UINT_MAX`, NULL pointers and strings, and `%c` with 0. Both the printed text and the returned length were compared. Both versions were also run under AddressSanitizer and UndefinedBehaviorSanitizer with no errors and no leaks.

## Resources

- `man 3 printf`: conversion specifiers, flags, width and precision.
- `man 3 stdarg`: `va_start`, `va_arg`, `va_copy`, `va_end`.
- `man 1 ar`: creating static libraries.
- [GNU Make manual](https://www.gnu.org/software/make/manual/): rules, prerequisites and phony targets.
- [cppreference, `printf`](https://en.cppreference.com/w/c/io/fprintf): the behaviour defined by the C standard.
- The 42 Norm and the ft_printf subject (v12.1).

### Use of AI

AI (Claude) was used for the following tasks:

- Reviewing the finished implementation and testing it against the system printf, including sanitizer runs, and checking the Makefile’s rebuild.
- behaviour against what the grader does.
- Explaining the behaviour of specific functions, their expected output, and likely failure cases.
- Helping to split the project from a single full-bonus implementation into separate mandatory and bonus versions.
- Detecting off-by-one errors in loops, segmentation faults, and inconsistent pointer handling between functions.
- Drafting this README from the subject and the final code.