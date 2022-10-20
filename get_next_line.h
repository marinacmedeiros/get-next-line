/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:21:40 by mamedeir          #+#    #+#             */
/*   Updated: 2022/10/20 15:12:12 by mamedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
/* The strlen() function calculates the length of the string
 pointed to by s, excluding the terminating null byte ('\0').*/
char	*ft_strchr(const char *s, int c);
/*The strchr() function returns a pointer to the first occurrence
 of the character c in the string s.*/
char	*ft_strjoin(const char *s1, const char *s2);
/*Allocates (with malloc(3)) and returns a new string, 
 which is the result of the concatenation of ’s1’ and ’s2’.*/

#endif
