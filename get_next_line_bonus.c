/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:13:24 by bahkaya           #+#    #+#             */
/*   Updated: 2025/07/21 17:13:34 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*new_temp(char *temp)
{
	char	*new_temp;
	char	*new_line;

	if (!temp)
		return (NULL);
	new_line = ft_strchr(temp, '\n');
	if (!new_line)
	{
		free(temp);
		return (NULL);
	}
	new_temp = ft_strdup(new_line + 1);
	free(temp);
	return (new_temp);
}

char	*get_line(char *temp)
{
	size_t	temp_len;
	size_t	new_line_len;
	char	*new_line;

	temp_len = ft_strlen(temp);
	if (!temp || *temp == '\0')
		return (NULL);
	new_line = ft_strchr(temp, '\n');
	if (!new_line)
		return (ft_substr(temp, 0, temp_len));
	new_line_len = ft_strlen(new_line);
	return (ft_substr(temp, 0, temp_len - new_line_len + 1));
}

char	*get_next_line(int fd)
{
	static char	*temp[4096];
	char		*buffer;
	ssize_t		total_read;
	char		*line;

	if (!temp[fd])
		temp[fd] = ft_strdup("");
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!ft_strchr(temp[fd], '\n'))
	{
		total_read = read(fd, buffer, BUFFER_SIZE);
		if (total_read == -1)
			return (free(buffer), NULL);
		if (total_read == 0)
			break ;
		buffer[total_read] = '\0';
		temp[fd] = ft_strjoin(temp[fd], buffer);
	}
	free(buffer);
	line = get_line(temp[fd]);
	temp[fd] = new_temp(temp[fd]);
	return (line);
}
