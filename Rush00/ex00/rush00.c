/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:56:23 by tnaton            #+#    #+#             */
/*   Updated: 2021/08/08 20:43:01 by bvanesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_topbtmline(int x, int countx)
{
	while (countx < x)
	{
		if (countx == 0 || countx == (x - 1))
			ft_putchar('o');
		else
			ft_putchar('-');
		countx ++;
	}
}

void	ft_midline(int x, int countx)
{
	while (countx < x)
	{
		if (countx == 0 || countx == (x - 1))
			ft_putchar('|');
		else
			ft_putchar(' ');
		countx ++;
	}
}

void	rush(int x, int y)
{
	int	countx;
	int	county;

	if ((x > 0) && (y > 0))
	{
		county = 0;
		while (county < y)
		{
			countx = 0;
			if (county == 0 || county == (y - 1))
				ft_topbtmline(x, countx);
			else
				ft_midline(x, countx);
			ft_putchar('\n');
			county ++;
		}
	}
}
