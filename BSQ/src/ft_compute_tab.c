/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:25:05 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/25 17:30:34 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_new_sq(t_map_attr *attr, int size_sq, int y_sq, int x_sq)
{
	attr->size_sq = size_sq;
	attr->y_sq = y_sq;
	attr->x_sq = x_sq;
}

int	ft_new_value(int **tab, int line, int pos, int *array)
{
	int	min;

	min = array[pos - 1];
	if (min > tab[line - 1][pos - 1])
		min = tab[line - 1][pos - 1];
	if (min > tab[line - 1][pos])
		min = tab[line - 1][pos];
	return (min + 1);
}

int	*ft_res_first_line(t_map_attr *attr, char *str, int *array)
{
	int	pos;

	pos = -1;
	while (++pos < attr->col_nb)
	{
		if (str[pos] == attr->empty_c)
		{
			if (attr->size_sq == 0)
				ft_new_sq(attr, 1, 0, pos);
			array[pos] = 1;
		}
		else if (str[pos] == attr->obstacle_c)
			array[pos] = 0;
		else
		{
			free(array);
			return (NULL);
		}
	}
	if (str[pos] != '\n')
	{
		free(array);
		return (NULL);
	}
	return (array);
}

int	*ft_res_first_col(t_map_attr *attr, int *array, int line, char *str)
{
	if (str[0] == attr->empty_c)
	{
		if (attr->size_sq == 0)
			ft_new_sq(attr, 1, line, 0);
		array[0] = 1;
	}
	else if (str[0] == attr->obstacle_c)
		array[0] = 0;
	else
	{
		free(array);
		return (NULL);
	}
	return (array);
}

int	*ft_res_center(int **tab, t_map_attr *attr, int *array, char *str)
{
	int	pos;

	pos = 0;
	if (!ft_res_first_col(attr, array, attr->c_line, str))
		return (NULL);
	while (++pos < attr->col_nb)
	{
		if (str[pos] == attr->empty_c)
		{
			array[pos] = ft_new_value(tab, attr->c_line, pos, array);
			if (array[pos] > attr->size_sq)
				ft_new_sq(attr, array[pos], attr->c_line, pos);
		}
		else if (str[pos] == attr->obstacle_c)
			array[pos] = 0;
		else
		{
			free(array);
			return (NULL);
		}
	}
	return (array);
}
