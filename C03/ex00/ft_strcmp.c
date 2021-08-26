/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:27:51 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/11 11:48:56 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_unsigning_char(char s_i)
{
	unsigned char	uc;

	if (s_i < 0)
		uc = 256 + s_i;
	else
		uc = s_i;
	return (uc);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				result;
	unsigned int	i;
	unsigned char	ucs1;
	unsigned char	ucs2;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			ucs1 = ft_unsigning_char(s1[i]);
			ucs2 = ft_unsigning_char(s2[i]);
			result = ucs1 - ucs2;
			return (result);
		}
		i++;
	}
	ucs2 = ft_unsigning_char(s2[i]);
	result = -ucs2;
	return (result);
}
