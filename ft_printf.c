/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 14:20:50 by jdijkman      #+#    #+#                 */
/*   Updated: 2024/01/07 17:24:39 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(const char *str, int i)
{
	write(1, &str[i], 1);
	return (1);
}

static int	ft_func(const char *str, int i, va_list args)
{
	unsigned long	n;
	int				len;

	len = 1;
	if (str[i + 1] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (str[i + 1] == 's')
		len += ft_putstr(va_arg(args, char *)) - 1;
	else if (str[i + 1] == 'p')
	{
		n = va_arg(args, unsigned long);
		if (n == 0)
		{
			len += 4;
			write(1, "(nil)", 5);
		}
		else
		{
			write(1, "0x", 2);
			len += 1;
			ft_printaddr(n, &len, 0);
		}
	}
	return (len);
}

static int	ft_func2(const char *str, int i, va_list args)
{
	int	len;

	len = 0;
	if (str[i + 1] == 'd')
		len += ft_printint(args);
	else if (str[i + 1] == 'i')
		len += ft_printint(args);
	else if (str[i + 1] == 'u')
		len += ft_printunsigned(va_arg(args, unsigned int));
	else if (str[i + 1] == 'x')
		ft_printaddr((unsigned int)va_arg(args, int), &len, 0);
	else if (str[i + 1] == 'X')
		ft_printaddr((unsigned int)va_arg(args, int), &len, 1);
	else if (str[i + 1] == '%')
	{
		len++;
		write(1, "%", 1);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str, i);
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p')
				len += ft_func(str, i, args);
			else if (str[i + 1] == 'd' || str[i + 1] == 'u' || str[i + 1] == 'i'
				|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%')
				len += ft_func2(str, i, args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// int main(void)
// {
// 	//char *str = NULL;
// //	ft_printf("ftprintf: %c\n", '0');
// 	printf(" len :%d \n", ft_printf("hello %c", '0'));
// 	//ft_printf(" hello %c \n", '0', - 256);
// 	//printf("%s", str);
// }