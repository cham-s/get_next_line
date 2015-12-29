/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:25 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/29 16:29:02 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

static t_file	*fpnodenew(int fd)
{
	t_file			*new;

	new = (t_file *)ft_memalloc(sizeof(t_file));
	if (!new)
			return (NULL);
	new->fd = fd;
	new->buffer = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

static t_file	*fpintree(t_file **btree, int fd)
{
	t_file			*tmp;
	tmp = *btree;

	while (tmp)
	{
		if (fd == tmp->fd)
			return (tmp);
		if (fd > tmp->fd)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return (NULL);
}

static void		addnode(t_file **btree, t_file *new)
{
	t_file			*tmptree;
	t_file			*tmpnode;

	tmptree = *btree;
	if (!*btree)
		*btree = new;
	else
	{
		while(tmptree)
		{
			tmpnode = tmptree;
			if (new->fd > tmptree->fd)
			{
				tmptree = tmptree->right;
				if (!tmptree)
					tmpnode->right = new;
			}
			else
			{
				tmptree = tmptree->left;
				if (!tmptree)
					tmpnode->left = new;
			}
		}
	}
}

static int		getline(t_file *fpnode, char **line, int fd)
{
	int				ret;
	int				len;
	char			buf[BUFF_SIZE + 1];

	len = 0;
	ret = BUFF_SIZE;
	while (!(ft_strchr(fpnode->buffer, '\n')) && ret)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (ret);
		buf[ret] = '\0';
		fpnode->buffer = ft_strjoin(fpnode->buffer, buf);
	}
	while (fpnode->buffer[len] && fpnode->buffer[len] != '\n')
		len++;
	*line = ft_strndup(fpnode->buffer, len);
	fpnode->buffer += len;
	if (*(fpnode->buffer) == '\n')
		(fpnode->buffer)++;
	if (!ret)
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_file	*btree = NULL;
	t_file			*fpnode;
	int				res;
	char			*tmp;

	tmp = NULL;
	if (fd < 0 || !line)
		return (-1);
	else
	{
		if (!(fpnode = fpintree(&btree, fd)))
		{
			fpnode = fpnodenew(fd);
			addnode(&btree, fpnode);
		}
		if (!(fpnode->buffer))
		{
			fpnode->buffer = ft_strdup("");
			tmp = fpnode->buffer;
		}
		res = getline(fpnode, line, fd);
		return (res);
	}
}
