/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:53:59 by gbabeau           #+#    #+#             */
/*   Updated: 2019/12/20 13:15:35 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		init(char **c)
{
	size_t i;

	i = 0;
	if (!(*c = malloc(BUFFER_SIZE)))
		return (0);
	while (i < BUFFER_SIZE)
		(*c)[i++] = '\0';
	return (1);
}

int		init_variable(int *a, int *check_read, int *init_v, int *i)
{
	*a = 0;
	*check_read = 2;
	*init_v = 0;
	*i = 0;
	return (1);
}

int		read_end_buffer(char *c, char **line, int fin)
{
	int n;
	int size;
	int i;

	i = 0;
	size = 1;
	n = size_buffer(c);
	while (i < BUFFER_SIZE && c[i] == '\0')
		i++;
	if (*line != 0)
		size = ft_strlen(*line);
	*line = ft_copy(line, c, size);
	if (fin == 1 && (n) < BUFFER_SIZE && c[n] == '\n')
	{
		dell_buffer(c);
		return (-1);
	}
	dell_buffer(c);
	if (fin == 0 && BUFFER_SIZE == (n + i))
		return (1);
	if (fin == 0)
		return (-1);
	return (-2);
}

int		transfer(char **line, char *c)
{
	int a;
	int size;

	size = 1;
	if (*line != 0)
		size = ft_strlen(*line);
	a = 0;
	while (a < BUFFER_SIZE && c[a] != '\n')
		a++;
	*line = ft_copy(line, c, size);
	if (a == BUFFER_SIZE)
	{
		dell_buffer(c);
		return (2);
	}
	if (c[a] == '\n')
	{
		dell_buffer(c);
		return (1);
	}
	dell_buffer(c);
	free(c);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*c = 0;
	int			check_read;
	int			a;
	int			i;
	int			init_v;

	if (line == 0 || init_variable(&a, &check_read, &init_v, &i) == 0)
		return (-1);
	(*line) = 0;
	if (fd < 0 || BUFFER_SIZE == 0 || (c == 0 && !(init_v = init(&c))))
		return (-1);
	while (check_read == 2)
	{
		if (i == 0 && c[0] == '\0' && 0 > (a = read_end_buffer(c, line, 0)))
			return (a + 2);
		if (0 > (check_read = read(fd, c, BUFFER_SIZE)))
			return (check_read);
		if (check_read != BUFFER_SIZE)
			if (0 > (a = read_end_buffer(c, line, 1)))
				return (a + 2);
		if (!(check_read = transfer(line, c)))
			return (0);
		i++;
	}
	return (1);
}
