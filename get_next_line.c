/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:13:24 by bahkaya           #+#    #+#             */
/*   Updated: 2025/07/18 13:14:32 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// use malloc to read the files
// u cannot use solely with *
// Learn why doesn this happen

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buffer;
	ssize_t		readed;


		if (!temp)
			temp = ft_strdup("");
		/*if (!temp)
			return (NULL); */
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while ((readed = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readed] = '\0';
		temp = ft_strjoin(temp, buffer);
		if(ft_strchr(buffer,'\n'))
			break;
	}
	free(buffer);	
	return (buffer);
}

// char *get_next_line(int fd)
// {
//     static char *temp;
//     char *buffer;
//     ssize_t readed;

//     if (!temp)
//         temp = ft_strdup("");

//     buffer = malloc(BUFFER_SIZE + 1);
//     if (!buffer)
//         return NULL;

//     while ((readed = read(fd, buffer, BUFFER_SIZE)) > 0)
//     {
//         buffer[readed] = '\0';
//         temp = ft_strjoin(temp, buffer);
//         if (ft_strchr(buffer, '\n')) // satır sonu varsa dur
//             break;
//     }
//     free(buffer);
//     return temp;
// }
