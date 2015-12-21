/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:25 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/21 13:13:40 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

int		line_read(int const fd, char **line)
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
			*line = buf;
			buf[ret] = '\0';
			tmp = readbuf;
			if (BUFF_SIZE > 1)
			{
				if (ft_memchr((const void*)buf, '\n', BUFF_SIZE))
				{
					split = ft_strsplit(buf, '\n');
					readbuf = ft_strjoin(readbuf, *split);
					*line = readbuf;
					return (1);
					readbuf = ft_strjoin(readbuf, buf);
				}
			}
			else
			{
				if (*buf == '\n')
				{
					*line = readbuf;
					return (1);
				}
				readbuf = ft_strjoin(readbuf, buf);
			}
			ft_strdel(&tmp);
		}
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	if (line_read(fd, line))
		return (1);
	//if (read_finished())
	//	return (0);
	else
		return (-1);
}
