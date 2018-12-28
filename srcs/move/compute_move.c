/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:48:45 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 16:08:29 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	can_place(t_grid *board, t_grid *piece, t_point *board_point, int playerid)
{
	int		overlaps;
	t_point	piece_point;
	char	board_val;

	overlaps = 0;
	piece_point.x = 0;
	piece_point.y = 0;
	while (1)
	{
		if (!in_bounds(board, piece, point_add(*board_point, piece_point)))
			return (0);
		if (get_cell_at(piece, piece_point) == 1)
		{
			board_val = get_cell_at(board, point_add(*board_point, piece_point));
			if (board_val != 0)
			{
				if (board_val == playerid)
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

int			compute_move(t_grid *board, t_grid *piece, t_point *point, int playerid)
{
	point->x = 0;
	point->y = 0;
	while (1)
	{
		if (can_place(board, piece, point, playerid))
			return (1);
		if (!get_next_cell(board, point))
			break ;
	}
	return (0);
}
