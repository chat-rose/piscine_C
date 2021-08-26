/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:45:57 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/05 16:46:02 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_display(int nb);

void	ft_putnbr(int nb)
{
	static int	signVar = 1;

	if (signVar && nb < 0)
	{
		ft_display(45);
		signVar = 0;
	}
	if (nb > 9 || nb < -9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		if (nb < 0)
			ft_display(-nb + 48);
		else
			ft_display(nb + 48);
	}
}

void	ft_display(int nb)
{
	write(1, &nb, 1);
}
