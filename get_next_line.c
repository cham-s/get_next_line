/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:25 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/19 14:22:10 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

int		read_file(char *filename);
{
	int		ret;
	int		fd;
	char	buf[BUF_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd > -1)
	{
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			
		}
	}
}
int		get_next_line(int const fd, char **line)
{

}
