/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 18:24:34 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int argc, char *argv[])
{
	t_gamestate	gamestate;
	t_point		move;
	t_bool		state;

	(void)argc;
	(void)argv;
	state = true;
	ft_bzero(&gamestate, sizeof(gamestate));
	read_head(&gamestate.playerid, (char*)&gamestate.playername);
	while (1)
	{
		parse_board(&gamestate.board);
		parse_piece(&gamestate.piece);
		if (!compute_move(&gamestate, &move))
		{
			move.x = 0;
			move.y = 0;
			state = false;
		}
		write_move(&move);
		grid_free(&gamestate.board);
		grid_free(&gamestate.piece);
		if (!state)
			break ;
	}
	return (0);
}
