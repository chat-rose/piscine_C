/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:07:09 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/15 22:08:26 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

void	ft_error(void);
void	ft_display(char board[4][4]);
int		ft_check_input(char *input);
void	ft_tab_input(char tab[4][4], char *input);
void	ft_obvious_board(char input[4][4], char board[4][4], char obvious[16]);
int		ft_double(char board[4][4], int pos, char v);
int		ft_obvious(int pos, char obvious[16]);
int		ft_pov(char input[4][4], char board[4][4], int pos, char v);
int		ft_back(char input[4][4], char board[4][4], int pos, char obvious[16]);

#endif
