/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect_input_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:52:03 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 17:37:46 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

/*
**	Reads on the standard input and verifies that it matches the specified
**	string. Does not read beyond the string len.
*/

void	expect_input_char(char expected)
{
	char	c;

	c = read_char();
	if (c != expected)
		error(MSG_PARSE_ERROR);
}
