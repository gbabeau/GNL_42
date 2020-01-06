/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:17:08 by gbabeau           #+#    #+#             */
/*   Updated: 2019/11/04 16:47:25 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*a;
	const char	*b;

	a = dest;
	b = src;
	if (!src || !dest)
		return (0);
	while (n--)
		*a++ = *b++;
	return (dest);
}

void	dell_buffer(char *c)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (i < BUFFER_SIZE && c[i] == '\0')
		i++;
	while (i < BUFFER_SIZE && c[i] != '\n')
		c[i++] = '\0';
	if (i < BUFFER_SIZE)
		c[i] = '\0';
}

int		size_buffer(char *c)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (n < BUFFER_SIZE && c[n] == '\0')
		n++;
	while ((i + n) < BUFFER_SIZE && c[i + n] != '\n')
		i++;
	return (i);
}

char	*ft_copy(char **line, char *c, int size)
{
	int		i;
	int		n;
	char	*line2;

	n = 0;
	i = size_buffer(c);
	if (!((line2) = malloc(size + i)))
		return (0);
	if (size != 0)
		ft_memcpy(line2, *line, size);
	if (*line != 0)
	{
		free(*line);
		*line = 0;
	}
	i = 0;
	while (n < BUFFER_SIZE && c[n] == '\0')
		n++;
	while ((i + n) < BUFFER_SIZE && c[i + n] != '\n')
	{
		line2[size - 1 + i] = c[i + n];
		i++;
	}
	line2[size - 1 + i] = '\0';
	return (line2);
}

int		ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	i++;
	return (i);
}
