/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:29:38 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 17:30:25 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
**	Reads a number from STDIN.
**	Expects the number of be finished by the specified character.
*/

int		read_number(char endchar)
{
	int		res;
	char	c;

	res = 0;
	while (1)
	{
		c = read_char();
		if (ft_isdigit(c))
		{
			res *= 10;
			res += (c - '0');
		}
		else if (c == endchar)
			break ;
		else
			error(MSG_PARSE_ERROR);
	}
	return (res);
}
