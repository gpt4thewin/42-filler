/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:48:09 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 17:10:49 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Verifies that "expected" is located at (str + pos)
**	and increments pos by the size of "expected".
*/

void	check_read_str(char *expected, char *str, int *pos)
{
	int	len;

	len = ft_strlen(expected);
	if (ft_strncmp(str + *pos, expected, len) != 0)
		error(MSG_PARSE_ERROR);
	(*pos) += len;
}
