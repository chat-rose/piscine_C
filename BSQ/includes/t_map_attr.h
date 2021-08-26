/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_attr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:17:19 by bdetune           #+#    #+#             */
/*   Updated: 2021/08/25 17:01:21 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_ATTR_H
# define T_MAP_ATTR_H

typedef struct s_map_attr
{
	int		col_nb;
	int		line_nb;
	char	empty_c;
	char	obstacle_c;
	char	full_c;
	int		x_sq;
	int		y_sq;
	int		size_sq;
	int		c_line;
}	t_map_attr;

#endif
