/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obvious_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:11:23 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/15 22:34:28 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ones_ud(char input[4][4], char board[4][4])
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < 2)
	{
		x = 0;
		while (x < 4)
		{
			if (input[y][x] == '1')
			{
				if (i < 1)
					board[0][x] = '4';
				else
					board[3][x] = '4';
			}
			x++;
		}
		i++;
		y++;
	}
}

void	ft_ones_lr(char input[4][4], char board[4][4])
{
	int	x;
	int	y;
	int	i;

	y = 2;
	i = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (input[y][x] == '1')
			{
				if (i < 1)
					board[x][0] = '4';
				else
					board[x][3] = '4';
			}
			x++;
		}
		i++;
		y++;
	}
}

void	ft_null_board(char board[4][4])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			board[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	ft_obvious_board(char input[4][4], char board[4][4], char obvious[16])
{
	int	y;
	int	x;
	int	i;

	i = 0;
	ft_null_board(board);
	ft_ones_ud(input, board);
	ft_ones_lr(input, board);
	while (i < 16)
	{
		y = i / 4;
		x = i % 4;
		if (board[y][x] != '0')
			obvious[i] = '1';
		else
			obvious[i] = '0';
		i++;
	}
	i = 0;
}
