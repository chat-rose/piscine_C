/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:38:04 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/13 14:25:21 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_check_base(char *base)
{
	int				j;
	unsigned int	sizeBase;

	j = 0;
	sizeBase = 0;
	while (base[sizeBase] != '\0')
	{
		if (base[sizeBase] == '+' || base[sizeBase] == '-')
			return (0);
		j = sizeBase + 1;
		while (base[j] != '\0')
		{
			if (base[sizeBase] == base[j])
				return (0);
			j++;
		}
		sizeBase++;
	}
	return (sizeBase);
}

void	ft_write_nbr_base(int nbr, char *base, unsigned int sizeBase)
{
	unsigned int	unbr;
	char			nbrC;

	if (nbr < 0)
	{
		write(1, "-", 1);
		unbr = -nbr;
	}
	else
		unbr = nbr;
	if (unbr > sizeBase - 1)
	{
		ft_write_nbr_base(unbr / sizeBase, base, sizeBase);
		ft_write_nbr_base(unbr % sizeBase, base, sizeBase);
	}
	else
	{
		nbrC = base[unbr];
		write(1, &nbrC, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	sizeBase;

	sizeBase = ft_check_base(base);
	if (sizeBase > 1)
		ft_write_nbr_base(nbr, base, sizeBase);
}
