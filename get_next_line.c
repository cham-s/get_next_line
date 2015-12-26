/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:25 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/26 17:15:21 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

static char		*readfd(int const fd)
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
		readbuf = ft_strjoin(readbuf, buf);
		ft_strdel(&tmp);
	}
	if (!readbuf)
		return (NULL);
	return (readbuf);
}

static t_file	*filenew(fd)
{
	t_file	*fp;
	size_t	len;
	char	*rbuf;

	rbuf = readfd(fd);
	len = ft_strlen(rbuf);
	fp = (t_file *)ft_memalloc(sizeof(t_file));
	if (!fp)
		return (NULL);
	if (!rbuf)
		fp->buffer = NULL;
	else
	{
		fp->buffer = (char *)ft_memalloc(sizeof(len));
		(void)ft_memcpy(fp->buffer, rbuf, len);
	}
	fp->fd = fd;
	fp->tmp = NULL;
	fp->next = NULL;
	return (fp);
}

static int		retline(t_file *fp, char **line)
{
	char	*t;
	char	*z;
	size_t	len;

	ft_putstr("char start in ascii: ");
	ft_putnbr(*(fp->buffer));
	ft_putendl("");
	if (!*(fp->buffer))
	{
		*line = NULL;
		return (0);
	}
	len = 0;
	*line = ft_strdup("");
	t = ft_memchr(fp->buffer, '\n', ft_strlen(fp->buffer));
	z = ft_memchr(fp->buffer, '\0', ft_strlen(fp->buffer));
	ft_putstr("at checking: ");
	ft_putnbr(*t);
	ft_putendl("");
	if (!z)
	{
		ft_putstr("at checking: ");
		ft_putnbr(0);
		ft_putendl("");
	}
	if(z)
		ft_putendl("true");
	if ((z && !t))
	{
		ft_putstr("char stop: ");
		ft_putchar(*z);
		ft_putendl("Z");
		len = z - fp->buffer;
	}
	if ((z && t) || (!z && t))
	{
		ft_putstr("char stop: ");
		ft_putchar(*t);
		ft_putendl("T");
		len = t - fp->buffer;
	}
	ft_putstr("Len: ");
	ft_putnbr(len);
	ft_putendl("");
	fp->tmp = *line;
	*line = ft_strnjoin(*line, fp->buffer, len);
	fp->buffer += len;
	ft_strdel(&fp->tmp);
	if(t)
		(fp->buffer)++;

	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_file *fplist = NULL;

	if (!fplist)
		fplist = filenew(fd);
	if (!fplist)
		return (-1);
	return (retline(fplist, line));
}
