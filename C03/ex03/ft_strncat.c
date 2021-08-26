/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:00:02 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/11 11:18:42 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	cntSrc;
	unsigned int	cntDest;

	cntSrc = 0;
	cntDest = 0;
	while (dest[cntDest] != '\0')
		cntDest++;
	while (src[cntSrc] != '\0' && cntSrc < nb)
	{
		dest[cntDest + cntSrc] = src[cntSrc];
		cntSrc++;
	}
	dest[cntDest + cntSrc] = '\0';
	return (dest);
}
