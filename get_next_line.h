/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:59:36 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/26 10:49:59 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_file
{
	int				fd;
	char			*buffer;
	struct s_file	*right;
	struct s_file	*left;
}				t_file;

int		get_next_line(int const fd, char **line);

#endif
