/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:09:18 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/15 22:53:39 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_back(char input[4][4], char board[4][4], int pos, char obvious[16])
{
	int		y;
	int		x;
	char	v;

	v = '1';
	if (pos == 16)
		return (1);
	y = pos / 4;
	x = pos % 4;
	if (obvious[pos] == '1')
	{
		if (ft_back(input, board, pos + 1, obvious) != 0)
			return (1);
	}
	else
	{
		while (v <= '4')
		{
			if ((ft_pov(input, board, pos, v) != 0)
				&& (ft_double(board, pos, v) != 0))
			{
				board[y][x] = v;
				if (ft_back(input, board, (pos + 1), obvious) != 0)
					return (1);
			}
			v++;
		}
	}
	if (obvious[pos] != '1')
		board[y][x] = '0';
	return (0);
}
