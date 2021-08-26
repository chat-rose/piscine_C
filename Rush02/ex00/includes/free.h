/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:24:17 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/22 21:39:01 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "struct_page.h"

int	free_string_array(char **tab);
int	free_page_array(t_page *tab);
int	free_all(t_page *tab, char **tab2);

#endif
