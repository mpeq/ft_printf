/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpequeno <mpequeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:34:37 by mpequeno          #+#    #+#             */
/*   Updated: 2021/12/03 23:41:36 by mpequeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	long long	nbr;
	int			len;

	nbr = n;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
		len += ft_printnbr(nbr / 10);
	len += ft_printchar(nbr % 10 + '0');
	return (len);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_printnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;
	int				len;

	base_len = ft_strlen(base);
	len = 0;
	if (n > base_len - 1)
		len += ft_printnbr_base(n / base_len, base);
	len += write(1, &base[n % base_len], 1);
	return (len);
}
