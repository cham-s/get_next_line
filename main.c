/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:01:22 by cattouma          #+#    #+#             */
/*   Updated: 2015/12/16 14:27:11 by cattouma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	func()
{
	static int x = 0;
	x++;
	printf("%d\n", x);
}

int		main(int ac, char **v)
{
	func();
	func();
	func();
	func();
	func();
	func();
	func();
}
