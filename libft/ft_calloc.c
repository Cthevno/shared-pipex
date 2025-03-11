/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:08:38 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:00:13 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > ((size_t) -1 / size))
		return (NULL);
	c = malloc(nmemb * size);
	if (c == NULL)
		return (NULL);
	ft_memset(c, 0, nmemb * size);
	return (c);
}
