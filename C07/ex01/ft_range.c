/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:13:46 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/23 14:49:35 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int				*tab;
	unsigned int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	if (!tab)
		return (NULL);
	while (min < max)
	{
		tab[i] = min++;
		i++;
	}
	return (tab);
}
