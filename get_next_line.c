/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:21:36 by mamedeir          #+#    #+#             */
/*   Updated: 2022/10/24 13:34:41 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_catch_line(str);
	if (!line)
		return (NULL);
	str = ft_save(str);
	return (line);
}

char	*ft_read(int fd, char *store)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(store, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		store = ft_strjoin(store, buffer);
	}
	free(buffer);
	if (read_bytes == -1)
		return (NULL);
	return (store);
}

char	*ft_catch_line(char *store)
{
	int		i;
	char	*s;

	i = 0;
	/* s = ""; */
	if (!store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (0);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		s[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		s[i] = store[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *store)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if ((store[i] == '\n' && store[i + 1] == '\0') || !store[i])
	{
		free (store);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!s)
		return (0);
	i++;
	j = 0;
	while (store[i])
		s[j++] = store[i++];
	s[j] = '\0';
	free(store);
	return (s);
}
