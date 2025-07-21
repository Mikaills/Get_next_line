/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:09:04 by bahkaya           #+#    #+#             */
/*   Updated: 2025/07/21 17:14:12 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!temp | !buffer)
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
	free(temp);
	return (total_str);
}

char	*ft_strchr(char *s, int c)
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

static size_t	ft_check_len(unsigned int start, size_t len, size_t s_len)
{
	size_t	sub_len;

	sub_len = 0;
	if (s_len - start < len)
		sub_len = s_len - start;
	else
		sub_len = len;
	return (sub_len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	s_len;
	size_t	sub_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		substr = ft_strdup("");
		return (substr);
	}
	sub_len = ft_check_len(start, len, s_len);
	substr = malloc(sizeof(char) * (sub_len + 1));
	if (!substr)
		return (NULL);
	while (i < sub_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[sub_len] = '\0';
	return (substr);
}
