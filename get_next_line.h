/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:36 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/19 16:56:18 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 64

typedef		struct	s_line
{
	struct	s_list	*next;
	char			*line;
}					t_line;

int					get_next_line(int const fd, char **line);
int					read_file(char *filename);

#endif
