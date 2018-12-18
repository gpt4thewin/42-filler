/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_head.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:24:06 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 17:38:00 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	read_number(void)
{
	char	c;

	if (read(STDIN_FILENO, &c, sizeof(c)) < 0)
		error(MSG_READ_ERROR);
	if (c != '1' && c != '2')
		error(MSG_PARSE_ERROR_HEAD);
	return (c - '0');
}

/*
**	Read the player name part.
**	Example:
**	[PLAYER_NAME]
*/

static void	read_name(char *name)
{
	char	c;
	int		state;
	size_t	len;

	check_input("[");
	len = 0;
	while ((state = read(STDIN_FILENO, &c, sizeof(c))) && c != ']')
	{
		name[len] = c;
		len++;
	}
	if (len == 0)
		error(MSG_PARSE_ERROR_HEAD);
	if (state < 0)
		error(MSG_READ_ERROR);
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
	check_input("$$$ exec p");
	*id = read_number();
	check_input(" : ");
	read_name(name);
	check_input("\n");
}
