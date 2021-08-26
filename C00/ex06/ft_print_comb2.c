/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:34:08 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/05 16:34:13 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	ft_display(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!(a == 57 && b == 56))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = 47;
	c = 47;
	while (++a <= 57)
	{
		b = 47;
		d = 48;
		while (++b <= 57)
		{
			while (++c <= 57)
			{
				while (++d <= 57)
					ft_display(a, b, c, d);
				d = 47;
			}
			d = b + 1;
			c = a - 1;
		}
		c = a;
	}
}
