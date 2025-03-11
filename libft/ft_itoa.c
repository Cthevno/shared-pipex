/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:13:01 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:00:27 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lennb(int n)
{
	int	i;

	i = 0;
	if (n > 0)
	{
		while (n > 9)
		{
			n /= 10;
			i++;
		}
	}
	else if (n < 0)
	{
		while (n < -9)
		{
			n /= 10;
			i++;
		}
	}
	if (n < 0)
		return (i + 2);
	else
		return (i + 1);
}

char	*ft_pntochar(char *s, int index, int n)
{
	while (index >= 0)
	{
		s[index] = (n % 10) + '0';
		n /= 10;
		index--;
	}
	return (s);
}

char	*ft_nntochar(char *s, int index, int n)
{
	if (n == -2147483648)
	{
		s[index--] = '8';
		n /= 10;
	}
	n *= -1;
	while (index > 0)
	{
		s[index] = (n % 10) + '0';
		n /= 10;
		index--;
	}
	s[index] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		index;

	if (n > 2147483647 || n < -2147483648)
		return (NULL);
	if (n < 0 && n)
		s = malloc(sizeof(*s) * (ft_lennb(n) + 1));
	if (n >= 0)
		s = malloc(sizeof(*s) * (ft_lennb(n) + 1));
	if (!s)
		return (NULL);
	index = ft_lennb(n);
	s[index] = '\0';
	index--;
	if (n < 0)
		ft_nntochar(s, index, n);
	else if (n >= 0)
		ft_pntochar(s, index, n);
	return (s);
}
/*
int	main(void)
{
	int	n = -2147483648;
	printf("%s\n", ft_itoa(n));
	return (0);
}*/
