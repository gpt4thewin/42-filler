/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:59:31 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 17:28:25 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	print_line(t_board *board, int line)
{
	int		i;
	char	c;

	i = 0;
	while (i < board->width)
	{
		c = get_cell_at(board, i, line);
		if (c == 0)
			ft_putchar('.');
		else if (c == 1)
			ft_putchar('O');
		else if (c == 2)
			ft_putchar('X');
		else
			ft_putchar('?');
		i++;
	}
	ft_putchar('\n');
}

void		board_print(t_board *board)
{
	int	i;

	i = 0;
	while (i < board->height)
	{
		print_line(board, i);
		i++;
	}
}
