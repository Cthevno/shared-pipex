/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:10:02 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:03:00 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_switch_print(va_list args, const char *format, size_t *nbchars)
{
	if ((*(format + 1)) == 'u')
		ft_printf_u(va_arg(args, unsigned int), nbchars);
	else if ((*(format + 1)) == 'd' || (*(format + 1)) == 'i')
		ft_putnbr_printf(va_arg(args, int), nbchars);
	else if ((*(format + 1)) == 'c')
		ft_putchar_printf(va_arg(args, int), nbchars);
	else if ((*(format + 1)) == 's')
		ft_putstr_printf(va_arg(args, char *), nbchars);
	else if ((*(format + 1)) == '%')
		ft_putchar_printf('%', nbchars);
	else if ((*(format + 1)) == 'x' || (*(format + 1)) == 'X')
		ft_putnbr_hex_printf(va_arg(args, int), nbchars, *(format + 1));
	else if ((*(format + 1)) == 'p')
		ft_print_p(va_arg(args, void *), nbchars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	nbchars;

	va_start(args, format);
	nbchars = 0;
	while (*format != '\0')
	{
		if (*format == '%' && (*(format + 1)) != '\0')
		{
			ft_switch_print(args, format, &nbchars);
			format += 2;
		}
		else if (*format != '\0')
		{
			ft_putchar_printf(*format, &nbchars);
			format++;
		}
	}
	va_end (args);
	return (nbchars);
}
