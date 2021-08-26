/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:07:28 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/17 21:16:30 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_display_line(int board[10][11])
{	
	int		i;
	int		j;
	char	c;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (board[i][j] == 0)
			i++;
		c = i + '0';
		write(1, &c, 1);
		j++;
	}
	write(1, "\n", 1);
}

int	validity(int board[10][11], int col, int line)
{
	int	i;

	i = 1;
	while ((col - i) >= 0)
	{
		if (board[line][col - i] == 1)
			return (0);
		i++;
	}
	i = 1;
	while ((line - i) >= 0 && ((col - i) >= 0))
	{
		if (board[line - i][col - i] == 1)
			return (0);
		i++;
	}
	i = 1;
	while ((line + i) < 10 && ((col - i) >= 0))
	{
		if (board[line + i][col - i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int	backtracking(int board[10][11], int col, int *cnt)
{
	int		line;

	line = 0;
	if (col == 10)
	{
		ft_display_line(board);
		*cnt = *cnt + 1;
		return (0);
	}
	while (line < 10)
	{
		if (validity(board, col, line) == 1)
		{
			board[line][col] = 1;
			backtracking(board, col + 1, cnt);
		}
		board[line][col] = 0;
		line++;
	}
	return (0);
}

void	ft_null(int	board[10][11])
{
	int	col;
	int	line;

	line = 0;
	while (line < 10)
	{
		col = 0;
		while (col < 11)
		{
			board[line][col] = 0;
			col++;
		}
		line++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	col;
	int	cnt;
	int	board[10][11];

	col = 0;
	cnt = 0;
	ft_null(board);
	backtracking(board, col, &cnt);
	return (cnt);
}
