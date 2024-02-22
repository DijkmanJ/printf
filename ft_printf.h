/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 17:40:12 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/12/28 16:42:35 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include "ft_printf.h"

int		*ft_printaddr(unsigned long n, int *len, int up);
int		ft_putstr(char *str);
int		ft_printunsigned(unsigned int c);
void	ft_printunsigned2(unsigned int c);
int		ft_printf(const char *str, ...);
int		ft_printint(va_list args);

#endif