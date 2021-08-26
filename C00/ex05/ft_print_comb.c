/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:04:08 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/04 21:04:12 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_comb(void);

void	ft_display(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a < 55)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = 48;
	b = 49;
	c = 49;
	while (a <= 55)
	{
		while (b <= 56)
		{
			while (c < 57)
			{
				c++;
				ft_display(a, b, c);
			}
			c = b + 1;
			b++;
		}
		b = a + 1;
		a++;
	}
}
