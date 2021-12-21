/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpequeno <mpequeno@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:59:57 by mpequeno          #+#    #+#             */
/*   Updated: 2021/12/21 11:21:45 by mpequeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_printnbr(int n);
int	ft_printnbr_base(unsigned long n, char *base);

#endif
