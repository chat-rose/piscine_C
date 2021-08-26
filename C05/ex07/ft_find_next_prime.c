/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:06:19 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/18 12:35:32 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb >= 2)
	{
		i = 2;
		while ((nb / i) >= i)
		{
			if ((nb % i) == 0)
				return (0);
			i++;
		}
		return (1);
	}
	return (42);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		nb = 1;
	while (1)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}
