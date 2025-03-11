/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:38:23 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/07 13:03:12 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_printf_error(int n, size_t *nbchars)
{
	if (n == -2147483648)
	{
		write(2, "-2147483648", 11);
		*nbchars += 11;
	}
	else if (n < 0)
	{
		n *= -1;
		write(2, "-", 1);
		*nbchars += 1;
		ft_putnbr_printf_error(n, nbchars);
	}
	else if (n > 9)
	{
		ft_putnbr_printf_error(n / 10, nbchars);
		ft_putnbr_printf_error(n % 10, nbchars);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar_printf_error((n + '0'), nbchars);
	}
}
