/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:22:34 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/11 14:52:48 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	cntSrc;
	unsigned int	sizeDest;
	unsigned int	sizeSrc;

	cntSrc = 0;
	sizeSrc = 0;
	sizeDest = 0;
	while (dest[sizeDest] != '\0')
		sizeDest++;
	while (src[sizeSrc] != '\0')
		sizeSrc++;
	if (size <= sizeDest || size == 0)
		return (sizeSrc + size);
	while (src[cntSrc] != '\0' && (sizeDest + cntSrc) < (size - 1))
	{
		dest[sizeDest + cntSrc] = src[cntSrc];
		cntSrc++;
	}
	dest[cntSrc + sizeDest] = '\0';
	return (sizeDest + sizeSrc);
}
