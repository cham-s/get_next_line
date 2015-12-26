/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:01:22 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/26 17:15:24 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	if (0)
		ft_putendl("error");
	else
	{
		int fd;
		char *line;
		line = NULL;
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd , &line) == 1)
			ft_putendl(line);
	}
	return(0);
}
