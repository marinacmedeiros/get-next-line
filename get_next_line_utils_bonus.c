/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:28:49 by mamedeir          #+#    #+#             */
/*   Updated: 2022/10/24 15:31:41 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	ptr;

	ptr = c;
	if (!s)
		return (NULL);
	while (*s != ptr)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*p;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char *)malloc(len1 + len2 + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		p[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
	{
		p[len1] = s2[i];
		len1++;
	}
	p[len1] = '\0';
	free ((char *)s1);
	return (p);
}
