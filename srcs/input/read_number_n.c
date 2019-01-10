/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:29:38 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/10 15:09:01 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
**	Reads a specified number of digits.
*/

t_bool	read_number_n(int n, int *num)
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
			return (false);
		i++;
	}
	*num = res;
	return (true);
}
