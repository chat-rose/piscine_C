/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:21:45 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/23 22:26:48 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_base(char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_strcat(char *dest, char src);

void	ft_DB(int numDec, char *base_to, unsigned int sizeBaseTo, char **numStr)
{
	unsigned int	unbr;

	if (numDec < 0)
	{
		ft_strcat(*numStr, '-');
		unbr = -numDec;
	}
	else
		unbr = numDec;
	if (unbr > sizeBaseTo - 1)
	{
		ft_DB(unbr / sizeBaseTo, base_to, sizeBaseTo, numStr);
		ft_DB(unbr % sizeBaseTo, base_to, sizeBaseTo, numStr);
	}
	else
	{
		ft_strcat(*numStr, base_to[unbr]);
	}
}

int	ft_len(int numDec, unsigned int sizeBaseTo)
{
	int				out_len;
	unsigned int	unumDec;

	out_len = 1;
	if (numDec < 0)
	{
		unumDec = -numDec;
		out_len++;
	}
	else
		unumDec = numDec;
	while (unumDec >= sizeBaseTo)
	{
		unumDec = (unumDec / sizeBaseTo);
		out_len++;
	}
	out_len++;
	return (out_len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	sizeBaseTo;
	int				numDec;
	int				out_len;
	int				i;
	char			*numStr;

	sizeBaseTo = ft_check_base(base_to);
	if (ft_check_base(base_from) < 2 || sizeBaseTo < 2)
		return (NULL);
	numDec = ft_atoi_base(nbr, base_from);
	out_len = ft_len(numDec, sizeBaseTo);
	numStr = (char *)malloc(sizeof(char) * (out_len + 1));
	if (!numStr)
		return (NULL);
	i = 0;
	while (i <= out_len)
		numStr[i++] = '\0';
	ft_DB(numDec, base_to, sizeBaseTo, &numStr);
	return (numStr);
}
