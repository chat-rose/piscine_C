/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:30:06 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/23 11:50:08 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strlen_tot(int size, char **strs)
{
	int	i;
	int	strlen_tot;

	i = 0;
	strlen_tot = 0;
	while (i < size)
	{
		strlen_tot += ft_strlen(strs[i]);
		i++;
	}
	return (strlen_tot);
}

void	ft_strcat(char *dest, char *src)
{
	unsigned int	cntSrc;
	unsigned int	cntDest;

	cntSrc = 0;
	cntDest = 0;
	while (dest[cntDest])
		cntDest++;
	while (src[cntSrc])
	{
		dest[cntDest + cntSrc] = src[cntSrc];
		cntSrc++;
	}
}

char	*ft_big_str(int size, char	**strs, char *sep, char *str)
{
	int	i;

	ft_strcat(str, strs[0]);
	i = 1;
	while (i < size)
	{
		ft_strcat(str, sep);
		ft_strcat(str, strs[i]);
		i++;
	}
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*str;
	unsigned int	i;
	unsigned int	total_len;

	total_len = ft_strlen_tot(size, strs) + (size - 1) * ft_strlen(sep);
	if (size < 1)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= total_len)
		str[i++] = '\0';
	str = ft_big_str(size, strs, sep, str);
	return (str);
}
