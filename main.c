/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:01:22 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/19 16:35:04 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_putendl("error");
	else
	{
		int fd;
		char *line;
		line = NULL;
		fd = open(av[1], O_RDONLY);
		if (get_next_line(fd, &line) == 1)
		{
			ft_putendl("");
			char *read = ft_strjoin("Hello", "les amis");;
			ft_putendl(read);
			free(read);
		}
	}
	return(0);
}
