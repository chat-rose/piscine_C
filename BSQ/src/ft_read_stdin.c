/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 21:05:57 by bdetune           #+#    #+#             */
/*   Updated: 2021/08/25 22:45:51 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**ft_convert_map_stdin(t_map_attr *attr)
{
	int		**tab_map;
	char	*str;

	str = ft_define_map(0, attr);
	if (!str)
		return (NULL);
	tab_map = ft_init_tab(attr);
	if (!tab_map)
		return (NULL);
	attr->size_sq = 0;
	tab_map = ft_convert_strings(str, attr, tab_map, 0);
	if (!tab_map)
		return (NULL);
	return (tab_map);
}
