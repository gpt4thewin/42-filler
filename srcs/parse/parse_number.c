/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:29:38 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/17 19:34:16 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
**	Parses the number at the specified position.
*/

int	parse_number(char *str, int *pos)
{
	int	res;

	if (!ft_isdigit(str[*pos]))
		error(MSG_PARSE_ERROR);
	res = 0;
	while (ft_isdigit(str[*pos]))
	{
		res *= 10;
		res += (str[*pos] - '0');
		(*pos)++;
	}
	return (res);
}
