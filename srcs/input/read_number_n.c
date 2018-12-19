/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:29:38 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 17:30:44 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
**	Reads a specified number of digits.
*/

int		read_number_n(int n)
{
	int		res;
	char	c;
	int		i;

	res = 0;
	i = 0;
	while (i < n)
	{
		c = read_char();
		if (ft_isdigit(c))
		{
			res *= 10;
			res += (c - '0');
		}
		else
			error(MSG_PARSE_ERROR);
		i++;
	}
	return (res);
}
