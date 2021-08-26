/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:39:08 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/13 10:39:26 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int	unb;

	if (nb < 0)
	{
		write(1, "-", 1);
		unb = -nb;
	}
	else
		unb = nb;
	if (unb > 9)
	{
		ft_putnbr(unb / 10);
		ft_putnbr(unb % 10);
	}
	else
	{
		unb = unb + '0';
		write(1, &unb, 1);
	}
}
