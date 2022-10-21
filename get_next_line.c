/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:21:36 by mamedeir          #+#    #+#             */
/*   Updated: 2022/10/20 16:33:11 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cat_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

/*
1° - Quero pegar a linha e incluir as possibilidades dela existir, como quando não existir, quando existir sem a quebra de linha (a partir daqui já faz a malocagem) e quando houver a quebra de linha

2° - salvar o que peguei na função anterior

3° - ler e salvar, utilizando o buffer

4° - por último fazemos o gnl em si

*/



char	*get_next_line(int fd)
{

}
