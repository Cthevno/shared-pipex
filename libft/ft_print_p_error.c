/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:47:17 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/07 13:03:48 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_printf_error(unsigned long long n, size_t *nbchars)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		ft_putptr_printf_error(n / 16, nbchars);
		ft_putptr_printf_error(n % 16, nbchars);
	}
	else if (n >= 0 && n <= 15)
		ft_putchar_printf_error((base[n]), nbchars);
}

void	ft_print_p_error(void *ptr, size_t *nbchars)
{
	unsigned long long	addr;

	if (ptr == 0)
	{
		ft_putstr_printf_error("(nil)", nbchars);
		return ;
	}
	addr = (unsigned long long)ptr;
	ft_putstr_printf_error("0x", nbchars);
	ft_putptr_printf_error(addr, nbchars);
}
