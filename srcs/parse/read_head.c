/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_head.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:24:06 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 17:26:40 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Read the player name part.
**	Example:
**	[PLAYER_NAME]
*/

static void	read_name(char *name)
{
	char	c;
	size_t	len;

	expect_input_str("[");
	len = 0;
	while ((c = read_char()) != ']')
	{
		name[len] = c;
		len++;
	}
	if (len == 0)
		error(MSG_PARSE_ERROR_HEAD);
	name[len] = '\0';
}

/*
**	Parses the first input line.
**	Stores the player id and name.
**	Format example :
**	$$$ exec p1 : [PLAYER_NAME]
*/

void		read_head(int *id, char *name)
{
	expect_input_str("$$$ exec p");
	*id = read_number_n(1);
	expect_input_str(" : ");
	read_name(name);
	expect_input_lineend();
}
