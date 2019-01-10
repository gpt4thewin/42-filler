/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect_input_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:52:03 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/10 16:29:13 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

/*
**	Reads on the standard input and verifies that it matches the specified
**	string. Does not read beyond the string len.
*/

t_bool	expect_input_char(char expected)
{
	char	c;

	c = read_char();
	return (c == expected);
}
