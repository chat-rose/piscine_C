/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:11:52 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/11 10:45:09 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_dec_to_hex(char c)
{
	if (c > 9)
	{
		c = 'a' + (c - 10);
		write (1, &c, 1);
	}
	else
	{
		c = '0' + c;
		write (1, &c, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 32) && (str[i] <= 126)))
		{
			write(1, "\\", 1);
			if (str[i] < 0)
				c = 256 + str[i];
			else
				c = str[i];
			ft_dec_to_hex(c / 16);
			ft_dec_to_hex(c % 16);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
