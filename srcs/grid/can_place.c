/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:05:54 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 18:27:16 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Returns one if the specified piece can be placed at the specified
**	point "target" on the specified board.
*/

int	can_place(t_grid *board, t_grid *piece, t_point *target, int playerid)
{
	int		overlaps;
	t_point	piece_point;
	char	board_val;

	overlaps = 0;
	piece_point.x = 0;
	piece_point.y = 0;
	while (1)
	{
		if (!piece_in_bounds(board, piece, point_add(*target, piece_point)))
			return (0);
		if (get_cell_at(piece, piece_point) == 1)
		{
			board_val = get_cell_at(board, point_add(*target, piece_point));
			if (board_val != CELL_EMPTY)
			{
				if (player_has_cell(board_val, playerid))
					overlaps++;
				else
					return (0);
			}
			if (overlaps > 1)
				return (0);
		}
		if (!get_next_cell(piece, &piece_point))
			break ;
	}
	return (overlaps == 1);
}
