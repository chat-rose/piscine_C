/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 21:55:13 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/19 20:19:23 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base)
{
	int	sizeBase;
	int	j;

	j = 0;
	sizeBase = 0;
	while (base[sizeBase] != '\0')
	{
		if (base[sizeBase] == '+' || base[sizeBase] == '-' 
				|| base[sizeBase] == ' ' || base[sizeBase] == '\t' 
				|| base[sizeBase] == '\n' || base[sizeBase] == '\r'
				|| base[sizeBase] == '\v' || base[sizeBase] == '\f')
			return (0);
		j = sizeBase + 1;
		while (base[j] != '\0')
		{
			if (base[sizeBase] == base[j])
				return (0);
			j++;
		}
		sizeBase++;
	}
	return (sizeBase);
}

int	ft_convert_to_number(int i, char *str, char *base, int sizeBase)
{
	int	number;
	int	index_base;

	number = 0;
	while (str[i])
	{
		index_base = 0;
		while (base[index_base])
		{
			if (str[i] == base[index_base])
			{
				number = number * sizeBase + index_base;
				break ;
			}
			index_base++;
		}
		if (index_base == sizeBase)
			break ;
		i++;
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sizeBase;
	int	signFactor;
	int	i;
	int	nmbr;

	i = 0;
	nmbr = 0;
	signFactor = 1;
	sizeBase = ft_check_base(base);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		 || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signFactor = -signFactor;
		i++;
	}
	nmbr = ft_convert_to_number(i, str, base, sizeBase);
	return (nmbr * signFactor);
}
