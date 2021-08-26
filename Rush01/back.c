/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:09:18 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/15 22:52:15 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	write_nbr(char input[4][4], char board[4][4], int pos, char v)
{
	int		y;
	int		x;

	y = pos / 4;
	x = pos % 4;
	if ((ft_pov(input, board, pos, v) != 0)
		&& (ft_double(board, pos, v) != 0))
	{
		board[y][x] = v;
		return (1);
	}
	else
		return (0);
}

int	ft_back(char input[4][4], char board[4][4], int pos, char obvious[16])
{
	char	v;

	v = '1';
	if (pos == 16)
		return (1);
	if (obvious[pos] == '1')
	{
		if (ft_back(input, board, pos + 1, obvious) != 0)
			return (1);
	}
	else
	{
		while (v <= '4')
		{
			if (write_nbr(input, board, pos, v))
			{
				if (ft_back(input, board, (pos + 1), obvious))
					return (1);
			}
			v++;
		}
	}
	if (obvious[pos] != '1')
		board[pos / 4][pos % 4] = '0';
	return (0);
}
