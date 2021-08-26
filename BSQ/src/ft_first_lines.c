/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:15:54 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/25 22:12:20 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_read	*ft_add_link(char buf_c)
{
	t_read	*new_link;

	new_link = (t_read *)malloc(sizeof(t_read));
	if (!new_link)
		return (NULL);
	new_link->c = buf_c;
	new_link->next = NULL;
	return (new_link);
}

int	ft_first_read(int fd, t_read **begin)
{
	char			buf[1];
	long long		ret;
	t_read			*current;
	int				char_nb;

	char_nb = 0;
	ret = read(fd, buf, 1);
	while (ret > 0 && buf[0] != '\n')
	{
		if (char_nb == 0)
		{
			*begin = ft_add_link(buf[0]);
			current = *begin;
		}
		else
		{
			current->next = ft_add_link(buf[0]);
			current = current->next;
		}
		char_nb++;
		ret = read(fd, buf, 1);
	}
	return (char_nb);
}

char	*ft_join_chain(t_read *begin, int size)
{
	char	*str;
	int		i;
	t_read	*previous;

	str = (char *)malloc(sizeof(char) * (size + 2));
	if (!str)
	{
		ft_free_chain(begin);
		return (NULL);
	}
	str[size] = '\0';
	str[size + 1] = '\0';
	i = 0;
	while (i < size)
	{
		str[i] = begin->c;
		previous = begin;
		begin = begin->next;
		free(previous);
		i++;
	}
	return (str);
}

int	ft_atoi(char *str, int size)
{
	int	i;
	int	line_nb;

	i = 0;
	line_nb = 0;
	while (i < size && (str[i] >= '0' && str[i] <= '9'))
	{
		if (line_nb > (INT_MAX / 10))
			return (0);
		line_nb = line_nb * 10 + (str[i] - '0');
		i++;
	}
	if (i != (size))
		return (0);
	return (line_nb);
}
