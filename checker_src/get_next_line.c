/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:05:04 by lgollong          #+#    #+#             */
/*   Updated: 2022/07/22 10:55:54 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static char	*print_lines(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	line = (char *)malloc(sizeof(char) * ft_strlen(save) + 1);
	if (!line)
		return (NULL);
	while (save[i])
	{
		line[i] = save[i];
		i++;
		if (save[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

static char	*next_lines(char *save)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || !save[i + 1])
		return (free(save), NULL);
	if (save)
		i++;
	next_line = (char *)malloc(sizeof(char) * ft_strlen(save + i) + 1);
	if (!next_line)
		return (free(save), NULL);
	j = 0;
	while (save[i])
	{
		next_line[j] = save[i];
		j++;
		i++;
	}
	next_line[j] = '\0';
	free(save);
	return (next_line);
}

static char	*read_it(int fd, int bytes, char *save, char *buffer)
{
	char	*temp;

	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		if (save == NULL)
			save = ft_strdup("");
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*buffer;
	char			*lines;
	int				bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (free(buffer), NULL);
	save = read_it(fd, bytes, save, buffer);
	if (!save)
	{
		free(buffer);
		return (free(save), NULL);
	}
	free(buffer);
	lines = print_lines(save);
	save = next_lines(save);
	return (lines);
}
