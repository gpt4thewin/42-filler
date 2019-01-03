/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_enemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:22:36 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 14:41:44 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_nearest_enemy(t_gamestate *gamestate, t_point start, t_point *found)
{
	int		res;
	int		distance;
	t_point	point;
	char	val;

	res = -1;
	point_init(&point);
	while (get_next_cell(&gamestate->board, &point))
	{
		val = get_cell_at(&gamestate->board, point);
		if (player_is_enemy(gamestate->playerid, val))
		{
			distance = point_dist(start, point);
			if (res == -1 || distance < res)
			{
				res = distance;
				*found = point;
			}
		}
	}
	return (res);
}
