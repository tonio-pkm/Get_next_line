/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgarci <antgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:22:00 by antgarci          #+#    #+#             */
/*   Updated: 2026/07/13 13:45:26 by antgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_free(char *rest, char *buffer)
{
	char	*str;
	size_t	len;

	if (rest == NULL)
		len = ft_strlen(buffer) + 1;
	else
		len = ft_strlen(rest) + ft_strlen(buffer) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	if (rest != NULL)
		ft_strlcpy(str, rest, len);
	ft_strlcat(str, buffer, len);
	free(rest);
	return (str);
}

char	*extract_line(char *rest, char *jump)
{
	char	*str;
	int		len;

	len = ft_strlen(rest) - ft_strlen(jump) + 1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, rest, len + 1);
	return (str);
}

char	*extract_rest(char *jump)
{
	char	*str;
	int		len;

	len = ft_strlen(jump) - 1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, jump + 1, len + 1);
	return (str);
}

int	read_until_n(char **rest, int fd)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	while (search_end(*rest) == NULL && bytes > 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (-1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (-1);
		}
		if (bytes > 0)
			buffer[bytes] = '\0';
		if (bytes != 0)
			*rest = join_free(*rest, buffer);
		free(buffer);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*aux;

	if (read_until_n(&rest, fd) == -1)
		return (NULL);
	if (search_end(rest) == NULL && (!rest || rest[0] == '\0'))
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	if (search_end(rest) == NULL && rest)
	{
		line = rest;
		rest = NULL;
		return (line);
	}
	aux = rest;
	line = extract_line(rest, search_end(rest));
	rest = extract_rest(search_end(rest));
	free(aux);
	return (line);
}
