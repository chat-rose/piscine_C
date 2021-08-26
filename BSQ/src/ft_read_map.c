/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:02:54 by bdetune           #+#    #+#             */
/*   Updated: 2021/08/25 22:26:39 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_parse_first_line(int fd, t_map_attr *attr)
{
	int		size;
	t_read	*begin;
	char	*str;

	begin = NULL;
	size = 0;
	size = ft_first_read(fd, &begin);
	if (size < 4)
	{
		ft_free_chain(begin);
		return (1);
	}
	str = ft_join_chain(begin, size);
	if (!str)
		return (1);
	attr->full_c = str[size - 1];
	attr->obstacle_c = str[size - 2];
	attr->empty_c = str[size - 3];
	attr->line_nb = ft_atoi(str, (size - 3));
	free(str);
	if (ft_check_map_attr(attr))
		return (1);
	return (0);
}

char	*ft_define_map(int fd, t_map_attr *attr)
{
	int		size;
	t_read	*begin;
	char	*str;

	if (ft_parse_first_line(fd, attr))
		return (NULL);
	begin = NULL;
	size = 0;
	size = ft_first_read(fd, &begin);
	if (size < 1)
	{
		ft_free_chain(begin);
		return (NULL);
	}
	attr->col_nb = size;
	str = ft_join_chain(begin, size);
	str[size] = '\n';
	return (str);
}

int	**ft_init_tab(t_map_attr *attr)
{
	int	**tab;
	int	i;

	tab = (int **)malloc(sizeof(int *) * (attr->line_nb + 1));
	if (!tab)
		return (NULL);
	i = 0;
	tab[attr->line_nb] = NULL;
	return (tab);
}

int	**ft_convert_strings(char *str, t_map_attr *attr, int **tab, int fd)
{
	long long	ret;
	long long	buf_size;

	attr->c_line = 0;
	buf_size = attr->col_nb + 1;
	ret = buf_size;
	while (ret == buf_size && attr->c_line < attr->line_nb)
	{
		tab[attr->c_line] = ft_resolve_map(tab, attr, str);
		if (!tab[attr->c_line])
			break ;
		attr->c_line += 1;
		ret = read(fd, str, buf_size);
	}
	free(str);
	if (attr->c_line != attr->line_nb || ret != 0)
	{
		tab[attr->c_line] = NULL;
		ft_free_tab(&tab);
		return (NULL);
	}
	return (tab);
}

int	**ft_convert_map(char *map_file, t_map_attr *attr)
{
	int		fd;
	int		**tab_map;
	char	*str;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = ft_define_map(fd, attr);
	if (!str)
	{
		close(fd);
		return (NULL);
	}
	tab_map = ft_init_tab(attr);
	if (!tab_map)
	{
		close(fd);
		return (NULL);
	}
	attr->size_sq = 0;
	tab_map = ft_convert_strings(str, attr, tab_map, fd);
	close(fd);
	if (!tab_map)
		return (NULL);
	return (tab_map);
}
