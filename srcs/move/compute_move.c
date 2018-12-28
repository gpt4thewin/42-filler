/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:48:45 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 16:47:10 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			compute_move(t_gamestate *gamestate, t_point *point)
{
	point->x = 0;
	point->y = 0;
	while (1)
	{
		if (can_place(&gamestate->board, &gamestate->piece, point, gamestate->playerid))
			return (1);
		if (!get_next_cell(&gamestate->board, point))
			break ;
	}
	return (0);
}
