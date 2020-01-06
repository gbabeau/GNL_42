/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 00:03:26 by gbabeau           #+#    #+#             */
/*   Updated: 2019/11/04 16:40:13 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*ft_copy(char **line, char *c, int size);
int		init_variable(int *a, int *b, int *init_v, int *i);
int		init(char **c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	dell_buffer(char *c);
int		read_end_buffer(char *c, char **line, int i);
int		get_next_line(int fd, char **line);
int		ft_strlen(char *line);
int		size_buffer(char *c);
#endif
