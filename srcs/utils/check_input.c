/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:34:48 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 18:34:49 by juazouz          ###   ########.fr       */
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
