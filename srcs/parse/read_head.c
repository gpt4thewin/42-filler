/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_head.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:24:06 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/10 16:25:49 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Read the player name part.
**	Example:
**	[PLAYER_NAME]
*/

static t_bool	read_name(char *name)
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
		return (false);
	name[len] = '\0';
	return (true);
}

/*
**	Parses the first input line.
**	Stores the player id and name.
**	Format example :
**	$$$ exec p1 : [PLAYER_NAME]
*/

t_bool			read_head(int *id, char *name)
{
	return (expect_input_str("$$$ exec p") &&
			read_number_n(1, id) &&
			(*id == 1 || *id == 2) &&
			expect_input_str(" : ") &&
			read_name(name) &&
			expect_input_lineend());
}
