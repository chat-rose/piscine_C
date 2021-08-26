/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:17:51 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/22 15:20:03 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

int	count_words(char *s, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_contains(sep, s[i]))
			count++;
		while (s[i] && !ft_contains(sep, s[i]))
			i++;
		while (s[i] && ft_contains(sep, s[i]))
			i++;
	}
	return (count);
}

char	*get_word(char *s, int start, int end)
{
	int		i;
	char	*new;

	new = malloc(end - start + 1);
	if (!new)
		return (NULL);
	i = 0;
	while ((start + i) < end)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	**ft_split(char *str, char *sep)
{
	int		i;
	int		n;
	int		len;
	int		word;
	char	**tab;

	i = 0;
	word = 0;
	len = count_words(str, sep);
	tab = malloc((len + 1) * sizeof(*tab));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		n = i;
		while (str[i] && !ft_contains(sep, str[i]))
			i++;
		if (i - n != 0)
			tab[word++] = get_word(str, n, i);
		while (ft_contains(sep, str[i]))
			i++;
	}
	tab[word] = 0;
	return (tab);
}
