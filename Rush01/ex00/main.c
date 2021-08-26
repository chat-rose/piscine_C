/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:09:34 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/15 22:11:02 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	char	input[4][4];
	char	board[4][4];
	char	obvious[16];
	int		pos;

	if (argc == 2)
	{
		pos = 0;
		if (ft_check_input(argv[1]) == 0)
		{
			ft_error();
			return (1);
		}
		ft_tab_input(input, argv[1]);
		ft_obvious_board(input, board, obvious);
		if (!(ft_back(input, board, pos, obvious)))
			ft_error();
		else
			ft_display(board);
	}
	else
		ft_error();
	return (0);
}
