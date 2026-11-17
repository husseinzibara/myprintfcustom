#include "libft_printf.h"

static int	print_nul(t_spec *spec)
{
	int	pad;
	int	i;
	int	left;

	filter_mods(spec->mods, "-");
	left = (ft_strchr(spec->mods, '-') != NULL);
	pad = 0;
	if (spec->width > 1)
		pad = spec->width - 1;
	i = 0;
	if (left)
		write(1, "\0", 1);
	while (i++ < pad)
		write(1, " ", 1);
	if (!left)
		write(1, "\0", 1);
	return (pad + 1);
}

int	printstr(char *s, t_spec *spec, t_flag *flags)
{
	int	len;

	if (!s && (spec->prec < 0 || spec->prec >= 6))
		s = "(null)";
	else if (!s)
		s = "";
	s = ft_strdup(s);
	if (!s)
		return (0);
	s = trim_str(s, spec->prec);
	filter_mods(spec->mods, "-");
	len = apply_flags(&s, spec->width, spec->mods, flags);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

int	printchar(int c, t_spec *spec, t_flag *flags)
{
	int		len;
	char	*s;

	if (c == 0)
		return (print_nul(spec));
	s = malloc(2);
	if (!s)
		return (0);
	s[0] = (char)c;
	s[1] = '\0';
	filter_mods(spec->mods, "-");
	len = apply_flags(&s, spec->width, spec->mods, flags);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

int	printhex(unsigned int num, t_spec *spec, t_flag *flags)
{
	int		len;
	char	*s;

	s = ft_itobase(num, "0123456789abcdef");
	if (!s)
		return (0);
	if (num)
		filter_mods(spec->mods, "-#0");
	else
		filter_mods(spec->mods, "-0");
	apply_prec(&s, spec, num == 0);
	len = apply_flags(&s, spec->width, spec->mods, flags);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}

int	printHEX(unsigned int num, t_spec *spec, t_flag *flags)
{
	int		i;
	int		len;
	char	*s;

	s = ft_itobase(num, "0123456789ABCDEF");
	if (!s)
		return (0);
	if (num)
		filter_mods(spec->mods, "-#0");
	else
		filter_mods(spec->mods, "-0");
	apply_prec(&s, spec, num == 0);
	len = apply_flags(&s, spec->width, spec->mods, flags);
	i = -1;
	while (s[++i])
		s[i] = ft_toupper(s[i]);
	ft_putstr_fd(s, 1);
	free(s);
	return (len);
}
