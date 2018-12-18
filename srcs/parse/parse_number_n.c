/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:29:38 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/17 19:34:05 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
**	Parse a specified number of digits.
*/

int	parse_number_n(char *str, int *pos, int n)
{
	int	res;
	int	i;

	if (!ft_isdigit(str[*pos]))
		error(MSG_PARSE_ERROR);
	res = 0;
	i = 0;
	while (i < n)
	{
		if (!ft_isdigit(str[*pos]))
			error(MSG_PARSE_ERROR);
		res *= 10;
		res += (str[*pos] - '0');
		(*pos)++;
		i++;
	}
	return (res);
}
