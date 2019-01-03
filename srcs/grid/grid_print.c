/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:59:31 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 19:53:16 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	print_line(t_grid *grid, int line)
{
	int		i;
	char	c;
	t_point	point;

	point.y = line;
	i = 0;
	while (i < grid->width)
	{
		point.x = i;
		c = get_cell_at(grid, point);
		if (c == CELL_EMPTY)
			ft_putchar('.');
		else if (c == CELL_P1 || c == CELL_P1_NEW)
			ft_putchar('O');
		else if (c == CELL_P2 || c == CELL_P2_NEW)
			ft_putchar('X');
		else
			ft_putchar('?');
		i++;
	}
	ft_putchar('\n');
}

void		grid_print(t_grid *grid)
{
	int	i;

	i = 0;
	while (i < grid->height)
	{
		print_line(grid, i);
		i++;
	}
}
