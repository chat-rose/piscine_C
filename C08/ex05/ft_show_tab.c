/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:32:50 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/23 17:53:15 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

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

void	ft_putstr(char *str)
{
	unsigned int	i;
	unsigned char	uc;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 0)
			uc = str[i] + 256;
		else
			uc = str[i];
		write(1, &uc, 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
