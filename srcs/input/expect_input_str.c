/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect_input_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:00:17 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 17:05:04 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

/*
**	Reads on the standard input and verifies that it matches the specified
**	string. Does not read beyond the string len.
*/

void	expect_input_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		expect_input_char(str[i]);
		i++;
	}
}
