/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:25 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/19 17:21:11 by cattouma         ###   ########.fr       */
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
	t_list	*list;

	list = NULL;
	if (fd > -1)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			*line = buf;
			buf[ret] = '\0';
			ft_lstappend(&list, ft_lstnew((void *)buf, BUFF_SIZE));
		}
	}
	ft_lstprint(list);
	ft_memdel((void *)list);
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
