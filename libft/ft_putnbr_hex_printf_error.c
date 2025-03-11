/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_printf_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:32:52 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/07 13:03:05 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex_printf_error(unsigned int n, size_t *nbchars, char c)
{
	char	*base;
	char	*base2;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_putnbr_hex_printf_error(n / 16, nbchars, c);
		ft_putnbr_hex_printf_error(n % 16, nbchars, c);
	}
	else if (n >= 0 && n <= 15)
	{
		if (c == 'x')
			ft_putchar_printf_error((base[n]), nbchars);
		else if (c == 'X')
			ft_putchar_printf_error((base2[n]), nbchars);
	}
}
