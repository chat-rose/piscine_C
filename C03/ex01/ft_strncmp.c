/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:31:34 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/11 12:01:05 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_unsigning_char(int s_i)
{
	unsigned int	uc;

	if (s_i < 0)
		uc = 256 + s_i;
	else
		uc = s_i;
	return (uc);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				result;
	unsigned int	ucs1;
	unsigned int	ucs2;

	i = 0;
	while ((s1[i] != '\0') && (i < n))
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
	if ((i < n) && (s1[i] == '\0'))
	{
		ucs2 = ft_unsigning_char(s2[i]);
		result = -ucs2;
		return (result);
	}
	return (0);
}
