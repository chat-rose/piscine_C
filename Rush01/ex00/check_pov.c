/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:04:10 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/15 22:16:30 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	l_pov(char board[4][4], int pos, char v)
{
	char	max;
	char	cnt_tower;
	int		i;
	int		y;
	int		x;

	y = pos / 4;
	x = pos % 4;
	i = 0;
	max = '0';
	cnt_tower = '0';
	while (i < x)
	{
		if (board[y][i] > max)
		{
			max = board[y][i];
			cnt_tower++;
		}
		i++;
	}
	if (v > max)
		cnt_tower++;
	return (cnt_tower);
}

char	u_pov(char board[4][4], int pos, char v)
{
	char	max;
	int		cnt_tower;
	int		j;
	int		y;
	int		x;

	y = pos / 4;
	x = pos % 4;
	j = 0;
	max = '0';
	cnt_tower = '0';
	while (j < y)
	{
		if (board[j][x] > max)
		{
			max = board[j][x];
			cnt_tower++;
		}
		j++;
	}
	if (v > max)
		cnt_tower++;
	return (cnt_tower);
}

char	r_pov(char board[4][4], int pos, char v)
{
	char	max;
	int		cnt_tower;
	int		k;
	int		y;
	int		x;

	y = pos / 4;
	x = pos % 4;
	k = 2;
	max = v;
	cnt_tower = '1';
	while (k >= 0)
	{
		if (board[y][k] > max)
		{
			max = board[y][k];
			cnt_tower++;
		}
		k--;
	}
	return (cnt_tower);
}

char	d_pov(char board[4][4], int pos, char v)
{
	char	max;
	int		cnt_tower;
	int		l;
	int		x;
	int		y;

	y = pos / 4;
	x = pos % 4;
	l = 2;
	max = v;
	cnt_tower = '1';
	while (l >= 0)
	{
		if (board[l][x] > max)
		{
			max = board[l][x];
			cnt_tower++;
		}
		l--;
	}
	return (cnt_tower);
}

int	ft_pov(char input[4][4], char board[4][4], int pos, char v)
{
	int	y;
	int	x;

	y = pos / 4;
	x = pos % 4;
	if (l_pov(board, pos, v) > input[2][y])
		return (0);
	if (u_pov(board, pos, v) > input[0][x])
		return (0);
	if (x == 3)
	{
		if (r_pov(board, pos, v) != input[3][y]
				|| l_pov(board, pos, v) != input[2][y])
			return (0);
	}
	if (y == 3)
	{
		if (d_pov(board, pos, v) != input[1][x]
				|| u_pov(board, pos, v) != input[0][x])
			return (0);
	}
	return (1);
}
