/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 16:36:08 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/25 16:24:46 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**ft_insert_square(int **tab, t_map_attr *attr)
{
	int	pos_sq;
	int	line_sq;

	line_sq = attr->y_sq - attr->size_sq + 1;
	while (line_sq <= attr->y_sq)
	{
		pos_sq = attr->x_sq - attr->size_sq + 1;
		while (pos_sq <= attr->x_sq)
		{
			tab[line_sq][pos_sq] = -1;
			pos_sq++;
		}
		line_sq++;
	}
	return (tab);
}

void	ft_fill_str(int **tab, t_map_attr *attr, char *str, int line)
{
	int	pos;

	pos = 0;
	while (pos < attr->col_nb)
	{
		if (tab[line][pos] == 0)
			str[pos] = attr->obstacle_c;
		else if (tab[line][pos] > 0)
			str[pos] = attr->empty_c;
		else
			str[pos] = attr->full_c;
		pos++;
	}
	str[pos] = '\n';
	pos++;
	str[pos] = '\0';
}

int	ft_display(int **tab, t_map_attr *attr)
{
	int		line;
	char	*str;

	line = 0;
	tab = ft_insert_square(tab, attr);
	str = (char *)malloc(sizeof(char) * (attr->col_nb + 2));
	if (!str)
		return (1);
	while (line < attr->line_nb)
	{
		ft_fill_str(tab, attr, str, line);
		write(1, str, (attr->col_nb + 1));
		line++;
	}
	free(str);
	return (0);
}
