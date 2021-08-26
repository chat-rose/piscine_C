/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:50:54 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/07 21:48:52 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	bigger;
	int	cpt1;
	int	cpt2;

	cpt1 = 0;
	cpt2 = 1;
	while (cpt1 < size)
	{
		while (cpt2 < size)
		{
			if (tab[cpt1] > tab[cpt2])
			{
				bigger = tab[cpt1];
				tab[cpt1] = tab[cpt2];
				tab[cpt2] = bigger;
			}
			cpt2++;
		}
		cpt1++;
		cpt2 = cpt1 + 1;
	}
}
