/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdetune <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:11:22 by bdetune           #+#    #+#             */
/*   Updated: 2021/08/25 22:34:26 by bdetune          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int	ret;
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			ret = ft_bsq(argv[i]);
			if (ret)
				map_error();
			if (i < (argc - 1))
				write(1, "\n", 1);
			i++;
		}
	}
	else
	{
		ret = ft_bsq_stdin();
		if (ret)
			map_error();
	}
	return (0);
}
