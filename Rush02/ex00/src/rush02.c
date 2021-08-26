/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:50:49 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/22 22:48:14 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "utils2.h"
#include "init.h"
#include "struct_page.h"
#include "free.h"
#include "find_dict.h"
#include "file.h"

#define DEFAULT_DICT "assets/numbers.dict"
#define KEYS "assets/keys"

char	*parse_input(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*number;

	i = 0;
	while (str[i] && ft_contains("\t\n\r\v\f ", str[i]))
		i++;
	while (str[i] && str[i] == '0' && str[i + 1] != 0)
		i++;
	len = ft_strlen(str) ;
	number = malloc((len - i) + 1);
	if (!number)
		return (NULL);
	j = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
		number[j++] = str[i++];
	}
	number[j] = 0;
	return (number);
}

int	dict_has_all_keys(t_page *dict)
{
	int		i;
	int		j;
	int		cpt;
	char	**lines;

	lines = file_get_lines(KEYS);
	if (!lines)
		return (0);
	i = 0;
	while (lines[i])
	{
		j = 0;
		cpt = 0;
		while (dict[j].key)
		{
			if (ft_strcmp(lines[i], dict[j++].key) == 0)
				cpt++;
		}
		if (cpt == 0)
			return (0);
		i++;
	}
	return (1);
}

int	rush02(int ac, char **av)
{
	char	*dictname;
	t_page	*dict;
	char	*number;

	if (ac == 2)
		dictname = av[0];
	else
		dictname = DEFAULT_DICT;
	dict = parse_dict(dictname);
	if (!dict || has_duplicate_key(dict) || !dict_has_all_keys(dict))
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	number = parse_input(av[1]);
	if (!number || !*number)
	{
		ft_putstr("Error\n");
		return (1);
	}
	find_dict(dict, number);
	free(number);
	free_page_array(dict);
	return (0);
}
