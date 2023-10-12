/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:59:10 by hongbaki          #+#    #+#             */
/*   Updated: 2022/12/21 14:59:54 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
when Errors occur, return -1
*/
int	conditions(const char *per_next, va_list *a, int *len)
{
	int	ret;

	ret = 0;
	if (*per_next == 'c')
		ret = ft_putchar(va_arg(*a, int), len);
	else if (*per_next == 's')
		ret = ft_putstr(va_arg(*a, char *), len);
	else if (*per_next == 'p')
		ret = ft_print_memory(va_arg(*a, void *), len);
	else if (*per_next == 'd' || *per_next == 'i')
		ret = ft_putnbr(va_arg(*a, int), len);
	else if (*per_next == 'u')
		ret = ft_putnbr_u(va_arg(*a, int), len);
	else if (*per_next == 'x' || *per_next == 'X')
		ret = ft_puthex(va_arg(*a, int), *per_next, len);
	else if (*per_next == '%')
		ret = ft_putchar('%', len);
	return (ret);
}

/*
if '%' is found, send next text address
if '%' is not found, len++;
if error is -1, return error 
*/
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		error;

	len = 0;
	error = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			error = conditions(++str, &ap, &len);
		else
			error = ft_putchar(*str, &len);
		if (error < 0)
			return (error);
		str++;
	}
	va_end(ap);
	return (len);
}
