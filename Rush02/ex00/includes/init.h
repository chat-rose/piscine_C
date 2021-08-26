/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:29:45 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/22 16:53:34 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct_page.h"

t_page	*parse_dict(char *filename);
char	*parse_input(char *str);
int		has_duplicate_key(t_page *tab);

#endif
