/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:00:38 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/07 16:10:57 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	cpt;

	cpt = 0;
	while (cpt < size / 2)
	{
		tmp = tab[cpt];
		tab[cpt] = tab[size - cpt - 1];
		tab[size - cpt - 1] = tmp;
		cpt++;
	}
}
