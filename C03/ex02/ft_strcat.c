/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:54:02 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/11 12:21:18 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	cntSrc;
	unsigned int	cntDest;

	cntSrc = 0;
	cntDest = 0;
	while (dest[cntDest] != '\0')
		cntDest++;
	while (src[cntSrc] != '\0')
	{
		dest[cntDest + cntSrc] = src[cntSrc];
		cntSrc++;
	}
	dest[cntDest + cntSrc] = '\0';
	return (dest);
}
