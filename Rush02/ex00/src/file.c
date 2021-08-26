/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:13:28 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/22 15:17:39 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_split.h"

#define BUFF_SIZE 1024

int	file_get_size(char *filename)
{
	int		fd;
	int		len;
	int		ret;
	char	buff[BUFF_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	len = 0;
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		len += ret;
	}
	close(fd);
	return (len);
}

char	**file_get_lines(char *filename)
{
	int		fd;
	int		len;
	char	*buff;
	char	**lines;

	len = file_get_size(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buff = malloc(len + 1);
	if (!buff)
		return (NULL);
	read(fd, buff, len);
	close(fd);
	lines = ft_split(buff, "\n");
	free(buff);
	return (lines);
}
