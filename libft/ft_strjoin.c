/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:47:52 by ctheveno          #+#    #+#             */
/*   Updated: 2025/02/13 15:51:32 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	i = 0;
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	s3 = malloc(sizeof * s3 * (lens1 + lens2 + 1));
	if (!s3)
		return (NULL);
	while (i < lens1)
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens2)
	{
		s3[lens1 + i] = s2[i];
		i++;
	}
	s3[lens1 + lens2] = '\0';
	free(s1);
	return (s3);
}
