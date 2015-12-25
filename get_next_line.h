/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:36 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/25 17:24:11 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

typedef struct			s_file
{
	short				bsize;
	int					fd;
	char				*tmp;
	char				*buffer;
}						t_file;

int		get_next_line(int const fd, char **line);

#endif
