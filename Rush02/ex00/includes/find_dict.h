/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dict.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:13:56 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/22 21:13:09 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_DICT_H
# define FIND_DICT_H

void	find_dict(t_page *dict, char *str);
void	prep_value(t_page *dict, char *str, int str_len);
int		print_pack(t_page *dict, char *sstr, int sstr_len);
int		print_factor(t_page *dict, char first_char, int nb_zero);

#endif
