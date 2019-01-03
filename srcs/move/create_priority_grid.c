/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_priority_grid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:43:22 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 18:37:36 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define OCCUPIED (-127)
#define WORKING (-126)

static void	init_priority_grid(t_state *state, t_grid *fill_grid)
{
	t_point	point;
	char	val;

	point_init(&point);
	while (get_next_cell(&state->board, &point))
	{
		val = get_cell_at(&state->board, point);
		if (val != 0)
			set_cell_at(fill_grid, point, OCCUPIED);
		else
			set_cell_at(fill_grid, point, 0);
	}
}

static void	fill(t_grid *grid, int x, int y, int val)
{
	char	curr;
	t_point	point;

	point.x = x;
	point.y = y;
	curr = get_cell_at(grid, point);
	if (curr == OCCUPIED || curr == val)
		return ;
	set_cell_at(grid, point, val);
	fill(grid, x + 1, y, val);
	fill(grid, x - 1, y, val);
	fill(grid, x, y + 1, val);
	fill(grid, x, y - 1, val);
}

void		create_priority_grid(t_state *state)
{
	t_grid	fill_grid;

	grid_init(&fill_grid, state->board.height, state->board.width);
	init_priority_grid(state, &fill_grid);
}
