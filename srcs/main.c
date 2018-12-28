/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 16:51:17 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int argc, char *argv[])
{
	t_gamestate	gamestate;
	t_point		move;
	// int		stop = 1;

	(void)argc;
	(void)argv;
	ft_bzero(&gamestate.piece, sizeof(gamestate.piece));
	read_head(&gamestate.playerid, (char*)&gamestate.playername);
	while (1)
	{
		parse_board(&gamestate.board);
		parse_piece(&gamestate.piece);
		// grid_print(&board);
		// grid_print(&piece);
		if (!compute_move(&gamestate, &move))
		{
			error("Game over");
			break ;
		}
		write_move(&move);
		// while (stop)
		// 	;
	}
	return (0);
}
