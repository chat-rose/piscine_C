/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:05:48 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/25 22:44:42 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h" 

int	map_error(void)
{
	write(2, "map error\n", 10);
	return (1);
}

int	ft_check_map_attr(t_map_attr *attr)
{
	if (attr->line_nb <= 0)
		return (1);
	if (attr->empty_c == attr->obstacle_c
		|| attr->empty_c == attr->full_c
		|| attr->obstacle_c == attr->full_c)
		return (1);
	if (attr->empty_c < ' ' || attr->empty_c > '~'
		|| attr->obstacle_c < ' ' || attr->obstacle_c > '~'
		|| attr->full_c < ' ' || attr->full_c > '~')
		return (1);
	return (0);
}

int	*ft_resolve_map(int **tab, t_map_attr *attr, char *str)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * (attr->col_nb));
	if (!array)
		return (NULL);
	if (attr->c_line == 0)
		return (ft_res_first_line(attr, str, array));
	if (!ft_res_center(tab, attr, array, str))
		return (NULL);
	if (str[attr->col_nb] != '\n')
		return (NULL);
	return (array);
}
