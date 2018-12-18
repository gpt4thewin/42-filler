/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:12:59 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/17 17:13:02 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

/*
**	Reads on the standard input and verifies that it matches the specified
**	string. Does not read beyond the string len.
*/

void	check_input(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (read(STDIN_FILENO, &c, 1) <= 0)
			error(MSG_READ_ERROR);
		if (c != str[i])
			error(MSG_PARSE_ASSERT_ERROR);
		i++;
	}
}
