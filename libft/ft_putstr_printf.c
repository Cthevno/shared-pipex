/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:01:48 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:04:00 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_printf(char *s, size_t *nbchars)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		*nbchars += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_printf(s[i], nbchars);
		i++;
	}
}
