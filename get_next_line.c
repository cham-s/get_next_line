/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:25 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/24 12:00:04 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

static t_file	*readfd(int const fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	t_file	*fp;

	fp = (t_file *)ft_memalloc(sizeof(t_file));
	if (!fd)
		return (NULL);
	fp->buffer = ft_strdup("");
	fp->fd = fd;
	if (fd > -1)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			fp->tmp = fp->buffer;
			fp->buffer = ft_strjoin(fp->buffer, buf);
			ft_strdel(&(fp->tmp));
		}
		fp->line = NULL;
		fp->bsize = BUFF_SIZE;
		fp->curp = fp->buffer;
		ret = close(fd);
		return (fp);
	}
	return (NULL);
}

static char	*get_line(t_file *fp)
{
	char *t;
	char *buf;
	size_t len;

	len = 0;
	t = NULL;
	fp->line = ft_strdup("");
	buf = ft_strnew(fp->bsize);
	while (!t)
	{
		buf = ft_strncpy(buf, fp->buffer, fp->bsize);
		fp->tmp = fp->line;
		fp->line = ft_strjoin(fp->line, buf);
		(fp->buffer) += fp->bsize;
		t = ft_memchr(buf, '\n', fp->bsize);
		ft_strdel(&(fp->tmp));
	}
	buf = ft_strncpy(buf, fp->buffer, fp->bsize);
	len = t - fp->buffer;
	fp->line = ft_strnjoin(fp->line, buf, len);
	fp->buffer = ++t;
	fp->curp = fp->buffer;
	ft_strdel(&buf);
	return (fp->line);
}

int		get_next_line(int const fd, char **line)
{
	t_file *fp;

	fp = readfd(fd);
	if (!fp)
		return (-1);
	*line = get_line(fp);
	return(1);

}
