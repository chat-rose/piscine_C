/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:02:17 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/22 21:18:06 by jschapin         ###   ########.fr       */
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

int	print_factor(t_page *dict, char first_char, int nb_zero)
{
	int		i;
	char	*factor;

	if (nb_zero < 2)
		return (ERROR);
	i = 1;
	factor = malloc(nb_zero + 1);
	if (!factor)
		return (ERROR);
	factor[0] = first_char;
	while (i < nb_zero)
		factor[i++] = '0';
	factor[i] = 0;
	get_dict_value(dict, factor);
	free(factor);
	return (1);
}

int	print_pack(t_page *dict, char *sstr, int sstr_len)
{
	int	label;

	label = 3 - sstr_len;
	if (ft_strcmp(sstr, "000") == 0)
		return (EMPTY);
	if (label == 0)
		label = handle_cent(dict, sstr++, label);
	if (label == 1)
		label = handle_diz(dict, sstr++, label);
	if (label == 2)
		label = handle_unit(dict, sstr++, label);
	return (1);
}

void	prep_value(t_page *dict, char *str, int str_len)
{
	int		i;
	int		j;
	int		pack_size;
	char	buffer[4];

	pack_size = str_len % 3;
	if (pack_size == 0)
		pack_size = 3;
	i = 0;
	j = 0;
	while (str[i])
	{
		buffer[j] = str[i];
		j++;
		i++;
		if (j == pack_size)
		{
			buffer[j] = '\0';
			if (print_pack(dict, buffer, j) != EMPTY)
				print_factor(dict, '1', str_len - i + 1);
			j = 0;
			pack_size = 3;
		}
	}
}

void	find_dict(t_page *dict, char *str)
{
	int		str_len;

	str_len = ft_strlen(str);
	if (str_len > 39)
	{
		ft_putstr("Dict Error\n");
		return ;
	}
	if (*str == '0')
		ft_putstr("zero");
	else
		prep_value(dict, str, str_len);
	ft_putchar('\n');
}
