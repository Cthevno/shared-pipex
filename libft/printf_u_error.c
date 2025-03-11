/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:20:30 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/07 13:03:28 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_u_error(unsigned int n, size_t *nbchars)
{
	if (n > 9)
	{
		ft_printf_u_error(n / 10, nbchars);
		ft_printf_u_error(n % 10, nbchars);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar_printf_error((n + '0'), nbchars);
	}
}
