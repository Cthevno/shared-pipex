/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:33:57 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:01:47 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if ((char )s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	if ((char )c == '\0')
		return ((char *)s);
	return (NULL);
}
