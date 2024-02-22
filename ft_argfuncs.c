/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_argfuncs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/20 14:04:12 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/12/28 16:50:19 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_printaddr(unsigned long n, int *len, int up)
{
	char	*str;

	if (up == 0)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_printaddr(n / 16, len, up);
		ft_printaddr(n % 16, len, up);
	}
	else
		*len += write(1, &str[n], 1);
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
		i++;
	write(1, &str[0], i);
	return (i);
}

void	ft_printunsigned2(unsigned int c)
{
	if (c > 9)
		ft_printunsigned2(c / 10);
	ft_putchar_fd((c % 10) + '0', 1);
}

int	ft_printunsigned(unsigned int c)
{
	int				len;
	unsigned int	temp;

	len = 0;
	temp = c;
	if (temp == 0)
		len ++;
	while (temp != 0)
	{
		temp = temp / 10;
		len ++;
	}
	ft_printunsigned2(c);
	return (len);
}

int	ft_printint(va_list args)
{
	char	*s;
	int		len;

	s = ft_itoa(va_arg(args, int));
	len = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (len);
}
