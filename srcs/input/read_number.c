/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:29:38 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/10 15:24:04 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
**	Reads a number from STDIN.
**	Expects the number of be finished by the specified character.
*/

t_bool	read_number(char endchar, int *num)
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
			return (false);
	}
	*num = res;
	return (true);
}
