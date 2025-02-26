/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:20:30 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:04:49 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_u(unsigned int n, size_t *nbchars)
{
	if (n > 9)
	{
		ft_printf_u(n / 10, nbchars);
		ft_printf_u(n % 10, nbchars);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar_printf((n + '0'), nbchars);
	}
}
