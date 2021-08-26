/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:05:20 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/11 11:20:39 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	sizeFind;
	unsigned int	cntFind;
	unsigned int	cntStr;

	sizeFind = 0;
	cntStr = 0;
	while (to_find[sizeFind] != '\0')
		sizeFind++;
	if (sizeFind == 0)
		return (str);
	while (str[cntStr] != '\0')
	{
		cntFind = 0;
		while (str[cntStr + cntFind] == to_find[cntFind])
		{
			cntFind++;
			if (cntFind == sizeFind)
				return (&str[cntStr]);
		}
		cntStr++;
	}
	return (0);
}
