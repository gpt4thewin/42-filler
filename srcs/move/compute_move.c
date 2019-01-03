/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:48:45 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 18:24:13 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Returns the sum of the distance to the nearest enemy
**	for every point of the piece.
*/

static int		get_nearest_enemy_dist(t_gamestate *gamestate, t_list *elem)
{
	t_point	piece_point_origin;
	t_point	piece_point;
	t_point	enemy_point;
	int		dist_sum;

	piece_point_origin = *((t_point*)elem->content);
	dist_sum = 0;
	point_init(&piece_point);
	piece_point = piece_center(&gamestate->piece);
	get_nearest_enemy(gamestate,
						point_add(piece_point_origin, piece_point),
						&enemy_point);
	dist_sum += point_dist(point_add(piece_point_origin, piece_point),
							enemy_point);
	return (dist_sum);
}

/*
**	Creates a list of all possible moves.
*/

static void		create_moves_list(t_gamestate *gamestate, t_list **list)
{
	t_list	*new;
	t_point	point;

	point_init(&point);
	while (get_next_cell(&gamestate->board, &point))
	{
		if (can_place(&gamestate->board, &gamestate->piece, &point, gamestate->playerid))
		{
			new = ft_lstnew(&point, sizeof(point));
			ft_lstadd(list, new);
			if (gamestate->stage == STAGE_EZPZ)
				return ;
		}
	}
}

static t_list	*lst_get_minby(t_list *lst, int (*f)(t_gamestate *gamestate, t_list *elem), t_gamestate *gamestate)
{
	t_list	*curr;
	t_list	*res;
	int		res_int;
	int		tmp;

	curr = lst;
	res_int = -1;
	res = NULL;
	while (curr != NULL)
	{
		tmp = f(gamestate, curr);
		if (res_int == -1 || tmp < res_int)
		{
			res = curr;
			res_int = tmp;
		}
		curr = curr->next;
	}
	return (res);
}

static void		update_stage(t_gamestate *gamestate, t_point *point)
{
	t_list	move;
	int		enemy_dist;

	move.content = point;
	enemy_dist = get_nearest_enemy_dist(gamestate, &move);
	if (gamestate->stage == STAGE_INITIAL || gamestate->stage == STAGE_EZPZ)
	{
		if (enemy_dist <= 1)
		{
			gamestate->stage = STAGE_CONTACT;
		}
	}
	else if (gamestate->stage == STAGE_CONTACT)
	{
		if (enemy_dist > 7)
		{
			gamestate->stage = STAGE_EZPZ;
		}
	}
}

int				compute_move(t_gamestate *gamestate, t_point *point)
{
	t_list	*moves;

	moves = NULL;
	create_moves_list(gamestate, &moves);
	if (moves == NULL)
		return (0);
	if (gamestate->stage == STAGE_EZPZ)
	{
		*point = *(t_point*)moves->content;
	}
	else
	{
		*point = *(t_point*)lst_get_minby(moves, get_nearest_enemy_dist, gamestate)->content;
	}
	update_stage(gamestate, point);
	ft_lstdel(&moves, NULL);

	return (1);
}
