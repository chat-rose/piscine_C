/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:06:11 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/15 22:06:41 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_double(char board[4][4], int pos, char v)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = pos / 4;
	x = pos % 4;
	i = 0;
	j = 0;
	while (i < 4)
	{
		if (board[y][i] == v)
			return (0);
		i++;
	}	
	while (j < 4)
	{
		if (board[j][x] == v)
			return (0);
		j++;
	}
	return (1);
}
