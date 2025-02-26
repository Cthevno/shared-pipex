/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:55:33 by ctheveno          #+#    #+#             */
/*   Updated: 2025/01/22 11:09:02 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(unsigned long long nb, int sign)
{
	unsigned long long	nb2;

	nb2 = nb * 10;
	nb2 /= 10;
	if (nb2 != nb)
	{
		if (sign == 1)
			return (1);
		else
			return (-1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned long long	nb;
	int					sign;

	nb = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		if (ft_check(nb, sign) == 1)
			return (-1);
		else if (ft_check(nb, sign) == -1)
			return (0);
		else
			nptr++;
	}
	return (nb * sign);
}
