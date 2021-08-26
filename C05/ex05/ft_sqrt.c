/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:57:48 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/16 14:23:36 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	racine;

	if (nb > 0)
	{
		racine = 1;
		while ((nb / racine) >= racine)
		{
			if ((nb % (racine * racine) == 0)
				&& (nb / (racine * racine) == 1))
				return (racine);
			racine++;
		}
	}
	return (0);
}
