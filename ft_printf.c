/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpequeno <mpequeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:16:03 by mpequeno          #+#    #+#             */
/*   Updated: 2021/12/03 23:45:58 by mpequeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(const char c, va_list args)
{
	if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_printnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_printnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_printnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == 'p')
	{
		write (1, "0x", 2);
		return (ft_printnbr_base(va_arg(args, unsigned long int),
				"0123456789abcdef") + 2);
	}
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len += write(1, &str[i], 1);
		else
			len += ft_sort(str[++i], args);
		i++;
	}
	va_end(args);
	return (len);
}
