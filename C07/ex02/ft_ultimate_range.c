/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:42:03 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/23 14:56:27 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				*tab;
	int				min_to_max;
	unsigned int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	min_to_max = max - min;
	tab = (int *)malloc(sizeof(*tab) * (min_to_max));
	if (!tab)
		return (-1);
	while (min < max)
		tab[i++] = min++;
	*range = tab;
	return (min_to_max);
}
