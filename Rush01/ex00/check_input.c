/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 21:59:54 by jschapin          #+#    #+#             */
/*   Updated: 2021/08/15 22:30:59 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_input(char *input)
{
	int	i;

	i = 0;
	if (ft_strlen(input) != 31)
		return (0);
	while (input[i] != '\0')
	{
		if ((i % 2 == 0) && !(input[i] >= '1' && input[i] <= '4'))
			return (0);
		else if ((i % 2 == 1) && input[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
