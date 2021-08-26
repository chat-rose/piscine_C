/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dict2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:50:01 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/22 21:07:04 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_DICT2_H
# define FIND_DICT2_H

int	handle_unit(t_page *dict, char *sstr, int label);
int	handle_diz(t_page *dict, char *sstr, int label);
int	handle_cent(t_page *dict, char *sstr, int label);
int	get_dict_value(t_page *dict, char *key);

#endif
