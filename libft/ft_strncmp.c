/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:16:18 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:01:42 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	if (n == 0)
		return (res);
	while ((s1[i] && s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			break ;
		else
			i++ ;
	}
	if (i < n)
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (res);
}
