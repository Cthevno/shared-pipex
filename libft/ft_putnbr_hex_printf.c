/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:32:52 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:03:28 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex_printf(unsigned int n, size_t *nbchars, char c)
{
	char	*base;
	char	*base2;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_putnbr_hex_printf(n / 16, nbchars, c);
		ft_putnbr_hex_printf(n % 16, nbchars, c);
	}
	else if (n >= 0 && n <= 15)
	{
		if (c == 'x')
			ft_putchar_printf((base[n]), nbchars);
		else if (c == 'X')
			ft_putchar_printf((base2[n]), nbchars);
	}
}
