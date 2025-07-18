/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:09:04 by bahkaya           #+#    #+#             */
/*   Updated: 2025/07/17 19:52:00 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *temp, char *buffer)
{
	size_t	i;
	size_t	k;
	size_t	temp_len;
	size_t	buffer_len;
	char	*total_str;

	i = 0;
	k = 0;
	if(!temp | !buffer)
		return (NULL);
	temp_len = ft_strlen(temp);
	buffer_len = ft_strlen(buffer);
	total_str = malloc(sizeof(char) * (temp_len + buffer_len) + 1);
	if (!total_str)
		return (NULL);
	while (temp[i] != '\0')
		total_str[k++] = temp[i++];
	i = 0;
	while (buffer[i] != '\0')
		total_str[k++] = buffer[i++];
	total_str[k] = '\0';
	return (total_str);
}
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char )c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((unsigned char )c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}