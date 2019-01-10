/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect_input_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:00:17 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/10 15:24:58 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

/*
**	Reads on the standard input and verifies that it matches the specified
**	string. Does not read beyond the string len.
*/

t_bool	expect_input_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!expect_input_char(str[i]))
			return (false);
		i++;
	}
	return (true);
}
