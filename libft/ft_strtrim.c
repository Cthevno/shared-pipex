/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:30:03 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:01:53 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (src[i] && i < n - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*strim;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = (ft_strlen((char *)s1) - 1);
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	if (end == 0)
	{
		strim = malloc(sizeof * strim * 1);
		strim[0] = '\0';
		return (strim);
	}
	strim = malloc(sizeof * strim *(end - start + 2));
	if (!strim)
		return (NULL);
	strim = ft_strncpy(strim, &s1[start], (end - start + 2));
	return (strim);
}
