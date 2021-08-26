/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dict2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:51:58 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/22 22:09:45 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "find_dict.h"
#include "find_dict2.h"
#include "utils2.h"
#include "utils.h"
#include <stdlib.h>

#define ERROR 42
#define EMPTY 0

int	get_dict_value(t_page *dict, char *key)
{
	static int	start = 0;

	while (dict->key)
	{
		if (ft_strcmp(key, dict->key) == 0)
		{
			if (start != 0)
				ft_putchar(' ');
			start = 1;
			ft_putstr(dict->value);
			return (0);
		}
		dict++;
	}
	return (ERROR);
}

int	handle_cent(t_page *dict, char *sstr, int label)
{
	char	hundred_unit[2];

	hundred_unit[0] = sstr[0];
	hundred_unit[1] = 0;
	if (*sstr != '0')
	{
		get_dict_value(dict, hundred_unit);
		get_dict_value(dict, "100");
	}
	return (label + 1);
}

int	handle_diz(t_page *dict, char *sstr, int label)
{
	if (*sstr != '0')
	{
		if (*sstr == '1')
		{
			get_dict_value(dict, sstr);
			return (label + 2);
		}
		else
		{
			print_factor(dict, sstr[0], 2);
			return (label + 1);
		}
	}
	return (label + 1);
}

int	handle_unit(t_page *dict, char *sstr, int label)
{
	if (*sstr != '0')
	{
		get_dict_value(dict, sstr);
		return (label + 1);
	}
	return (label + 1);
}
