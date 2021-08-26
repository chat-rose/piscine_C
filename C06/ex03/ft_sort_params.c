/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:06:03 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/16 12:06:04 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int				result;
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
		i++;
	}
	result = -s2[i];
	return (result);
}

void	ft_sort_char_tab(char **argv, int size)
{
	char	*bigger;
	int		i;
	int		j;

	i = 1;
	j = 2;
	while (i < size)
	{
		while (j <= size)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				bigger = argv[i];
				argv[i] = argv[j];
				argv[j] = bigger;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_char_tab(argv, (argc - 1));
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
