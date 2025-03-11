/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:29:49 by ctheveno          #+#    #+#             */
/*   Updated: 2025/03/04 14:34:02 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while ((s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			break ;
		else
			i++ ;
	}
	res = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (res);
}
