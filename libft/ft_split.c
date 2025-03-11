/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctheveno <ctheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:08:48 by ctheveno          #+#    #+#             */
/*   Updated: 2024/12/19 11:01:18 by ctheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(const char *s, char c)
{
	int	nbwords;
	int	i;

	i = 0;
	nbwords = 0;
	if (!*s)
		return (nbwords);
	if (s[0] != c)
		nbwords++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			nbwords++;
		i++;
	}
	return (nbwords);
}

int	ft_lenwords(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_freetab(char **tab, int j)
{
	while (j > 0)
		free(tab[--j]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	tab = malloc(sizeof (*tab) *(ft_countwords(s, c) + 1));
	if (!s || !tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			tab[j] = ft_substr(s, i, ft_lenwords(s + i, c));
			if (!tab[j])
				return (ft_freetab(tab, j));
			j++;
			i += ft_lenwords(s + i, c);
		}
	}
	tab[j] = NULL;
	return (tab);
}
