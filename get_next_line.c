/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:25 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/22 18:26:49 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

int			line_read(int const fd, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*readbuf;
	char	*tmp;
	char	**split;

	readbuf = ft_strdup("");
	if (fd > -1)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			tmp = readbuf;
			readbuf = ft_strjoin(readbuf, buf);
		}
		split = strsplit(readbuf, '\n');
		*line = *split;
		return (1);
	}
	return (-1);
}

int		get_next_line(int const fd, char **line)
{
	if (line_read(fd, line) > -1)
		return (1);
	else
		return (-1);
}
