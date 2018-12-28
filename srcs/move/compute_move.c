/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:48:45 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 16:17:54 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
