/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:34:13 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/23 13:10:11 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_word_cnt(char *str, char *charset)
{
	int	wc;

	wc = 0;
	while (*str)
	{
		while (*str && ft_is_sep(*str, charset) == 1)
			str++;
		if (*str && ft_is_sep(*str, charset) == 0)
		{
			while (*str && ft_is_sep(*str, charset) == 0)
				str++;
			wc++;
		}
	}
	return (wc);
}

int	ft_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str && ft_is_sep(*str, charset) == 0)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_sstr_mallocopy(char *str, char *charset, int *stt)
{
	char	*sstr;
	int		i;

	i = 0;
	sstr = NULL;
	while (str[*stt] && ft_is_sep(str[*stt], charset) == 1)
		*stt += 1;
	sstr = (char *)malloc(sizeof(char) * (ft_len(&str[*stt], charset) + 1));
	if (!sstr)
		return (NULL);
	while (str[*stt] && (ft_is_sep(str[*stt], charset) == 0))
	{
		sstr[i] = str[*stt];
		*stt += 1;
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		wc;
	int		stt;

	i = 0;
	stt = 0;
	wc = ft_word_cnt(str, charset);
	tab = (char **)malloc((sizeof(char *) * (wc + 1)));
	if (!tab)
		return (NULL);
	while (i < wc)
	{
		tab[i] = ft_sstr_mallocopy(str, charset, &stt);
		i++;
	}
	tab[wc] = NULL;
	return (tab);
}
