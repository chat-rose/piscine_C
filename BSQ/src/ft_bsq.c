/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:36:17 by bdetune           #+#    #+#             */
/*   Updated: 2021/08/25 19:54:56 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free_tab(int ***tab)
{
	unsigned int	i;

	i = 0;
	while (tab[0][i])
	{
		free(tab[0][i]);
		i++;
	}
	free(*tab);
}

void	ft_free_chain(t_read *begin)
{
	t_read	*current;

	while (begin)
	{
		current = begin->next;
		free(begin);
		begin = current;
	}
}

int	ft_bsq(char *map_file)
{
	int			**tab;
	int			success;
	t_map_attr	attr;

	tab = ft_convert_map(map_file, &attr);
	if (!tab)
		return (1);
	success = ft_display(tab, &attr);
	ft_free_tab(&tab);
	return (success);
}

int	ft_bsq_stdin(void)
{
	int			**tab;
	int			success;
	t_map_attr	attr;

	tab = ft_convert_map_stdin(&attr);
	if (!tab)
		return (1);
	success = ft_display(tab, &attr);
	ft_free_tab(&tab);
	return (success);
}
