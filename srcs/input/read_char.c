/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:58:08 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 18:40:41 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	read_char(void)
{
	char	c;
	int		state;

	while ((state = read(STDIN_FILENO, &c, 1)) <= 0)
	{
		if (state < 0)
			error(MSG_READ_ERROR);
	}
	return (c);
}
