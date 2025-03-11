/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:01:48 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/07 13:03:22 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_printf_error(char *s, size_t *nbchars)
{
	int	i;

	if (!s)
	{
		write(2, "(null)", 6);
		*nbchars += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_printf_error(s[i], nbchars);
		i++;
	}
}
