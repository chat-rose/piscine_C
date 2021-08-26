/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:23:44 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/22 22:19:15 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct_page.h"

int	free_string_array(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

int	free_page_array(t_page *tab)
{
	int	i;

	i = 0;
	while (tab && tab[i].key && tab[i].value)
	{
		free(tab[i].key);
		free(tab[i].value);
		i++;
	}
	if (tab[i].key)
		free(tab[i].key);
	if (tab[i].value)
		free(tab[i].value);
	free(tab);
	return (0);
}

int	free_all(t_page *tab, char **tab2)
{
	free_page_array(tab);
	free_string_array(tab2);
	return (0);
}
