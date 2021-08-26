/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:29:18 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/22 22:54:57 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_trim(char *s)
{
	int		i;
	int		j;
	int		s_len;
	int		new_len;
	char	*new;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	s_len = ft_strlen(s);
	new_len = s_len - i;
	new = malloc(new_len + 1);
	j = 0;
	while (s[i])
		new[j++] = s[i++];
	new[j--] = 0;
	while (new[j] == ' ')
		new[j--] = 0;
	if (new[0] == 0)
		return (0);
	return (new);
}
