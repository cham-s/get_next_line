/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:25 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/19 17:03:14 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

int		read_file(char *filename)
{
	int		ret;
	int		fd;
	char	buf[BUFF_SIZE + 1];
	char	**lines;
	t_list	*list;

	list = NULL;
	fd = open(filename, O_RDONLY);
	if (fd > -1)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			lines = ft_strsplit(buf, '\n');
			ft_lstadd(&list, ft_lstnew((void *)buf, ft_strlen(buf)));
			ft_putstr((char const*)list->content);
		}
	}
	return (1);
}

/*int		get_next_line(int const fd, char **line)
{

}*/
