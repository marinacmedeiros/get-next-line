/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:21:36 by mamedeir          #+#    #+#             */
/*   Updated: 2022/10/21 16:35:37 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_catch_line(char *store)
{
	int		i;
	char	*s;

	i = 0;
	if (!store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
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
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (store[i])
		s[j++] = store[i++];
	s[j] = '\0';
	free(store);
	return (s);
}

char	*ft_read_and_save(int fd, char *store)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(store, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		store = ft_strjoin(store, buff);
	}
	free(buff);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	store = ft_read_and_save(fd, store);
	if (!store)
		return (NULL);
	line = ft_get_line(store);
	store = ft_save(store);
	return (line);
}

/*1° - Quero pegar a linha e incluir as possibilidades dela existir,
como quando não existir, quando existir sem a quebra de linha 
(a partir daqui já faz a malocagem) e quando houver a quebra de linha

2° - salvar o que peguei na função anterior

3° - ler e salvar, utilizando o buffer

4° - por último fazemos o gnl em si*/