/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:13:39 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/11 10:51:46 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	sizeSrc;
	unsigned int	i;

	i = 0;
	sizeSrc = 0;
	while (src[sizeSrc] != '\0')
		sizeSrc++;
	if (size > 0)
	{
		while ((i < (size - 1)) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (sizeSrc);
}
