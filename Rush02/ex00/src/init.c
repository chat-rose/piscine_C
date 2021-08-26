/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:55:56 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/22 21:39:29 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct_page.h"
#include "utils.h"
#include "utils2.h"
#include "ft_split.h"
#include "free.h"
#include "file.h"

int	has_duplicate_key(t_page *tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i].key)
	{
		j = i + 1;
		while (tab[j].key)
		{
			if (ft_strcmp(tab[i].key, tab[j].key) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*get_key(char *line)
{
	int		i;
	int		start;
	char	*key;

	i = 0;
	while (line[i] && ft_contains(" \t", line[i]))
		i++;
	if (line[i] == '-')
		return (NULL);
	if (line[i] == '+')
		i++;
	start = i;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	key = malloc((i - start) + 1);
	if (!key)
		return (NULL);
	key[i-- - start] = 0;
	while (i >= start)
	{
		key[i - start] = line[i];
		i--;
	}
	return (key);
}

char	*get_value(char *line)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	while (line[i] != ':' && line[i] != 0)
		i++;
	if (!line[i++])
		return (NULL);
	len = ft_strlen(line);
	value = malloc((len - i) + 1);
	if (!value)
		return (NULL);
	value[len - i] = 0;
	len = -1;
	while (line[i + ++len])
	{
		if (line[i] < 32 || line[i] > 126)
		{
			free(value);
			return (0);
		}
		value[len] = line[i + len];
	}
	return (ft_trim(value));
}

void	create_page(t_page *page, char *key, char *value)
{
	page->key = key;
	page->value = value;
}

t_page	*parse_dict(char *filename)
{
	int		i;
	char	**lines;
	t_page	*dict;

	lines = file_get_lines(filename);
	if (!lines)
		return (NULL);
	i = 0;
	while (lines[i])
		i++;
	dict = malloc((i + 1) * sizeof(*dict));
	if (!dict)
		return (NULL);
	i = -1;
	while (lines[++i])
	{
		create_page(dict + i, get_key(lines[i]), get_value(lines[i]));
		if (!dict[i].key || !dict[i].value)
		{
			free_all(dict, lines);
			return (NULL);
		}
	}
	create_page(dict + i, 0, 0);
	return (dict);
}
