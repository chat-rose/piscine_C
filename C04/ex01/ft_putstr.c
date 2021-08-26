/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:38:16 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/13 10:38:21 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
