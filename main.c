/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:44:56 by cattouma          #+#    #+#             */
/*   Updated: 2016/01/25 18:45:05 by cattouma         ###   ########.fr       */
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
	int fd;
	int res;
	char *line;

	if (ac == 1)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);
	while ((res = get_next_line(fd , &line)))
	{
		ft_putstr("-> ");
		ft_putendl(line);
	}
	ft_putnbr(res);
	ft_putendl("");
	return(0);
}
