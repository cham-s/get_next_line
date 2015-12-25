/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:25 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/25 20:48:54 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

static char *readfd(int const fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char 	*readbuf;
	char 	*tmp;

	readbuf = ft_strdup("");
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = readbuf;
		readbuf = ft_strjoin(fp->buffer, buf);
		ft_strdel(&tmp);
	}
	if (!readbuf)
		return (NULL);
	return (readbuf)
}

static t_file	*filenew(fd)
{
	t_file *fp;
	size_t len;

	len = ft_strlen(bufcontent);
	fp = (t_file *)ft_memalloc(sizeof(t_file));
	if (!fp)
		return (NULL);
	if (!bufcontent)
		fp->buffer = NULL;
	else
	{
		fp->buffer = (char *)ft_memalloc(sizeof(len));
		(void)ft_memcpy(fp->buffer, bufcontent, len);
	}
	fp->bsize = BUFF_SIZE;
	fp->fd = fd;
	fp->tmp = NULL;
	fp->next = NULL;
}

static void	retline(t_file *fp, char **line)
{
	char *t;
	size_t len;

	len = 0;
	t = NULL;
	*line = ft_strdup("");
	while (!(t = ft_memchr(fp->buffer, '\n', fp->bsize)))
	{
		fp->tmp = *line;
		*line = ft_strnjoin(*line, fp->buffer, fp->bsize);
		fp->buffer += fp->bsize;
		ft_strdel(&fp->tmp);
	}
	len = t - fp->buffer;
	*line = ft_strnjoin(*line, fp->buffer, len);
	fp->buffer += len;
	(fp->buffer)++;
}


int		get_next_line(int const fd, char **line)
{
	static t_file *fp;

	fp = (t_file *)ft_memalloc(sizeof(t_file));
	if (!fp)
		return (-1);
	fp->fd = 0;
	if (fd == -1)
		return (-1);
	readfd(fd, fp, line);
	return(1);
}
