/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 15:04:05 by juazouz          ###   ########.fr       */
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
	ft_bzero(&gamestate, sizeof(gamestate));
	read_head(&gamestate.playerid, (char*)&gamestate.playername);
	while (1)
	{
		parse_board(&gamestate.board);
		parse_piece(&gamestate.piece);
		// grid_print(&gamestate.board);
		// grid_print(&gamestate.piece);
		if (!compute_move(&gamestate, &move))
		{
			ft_putendl_fd("Game over", STDERR_FILENO);
			grid_print(&gamestate.piece);
			break ;
		}
		write_move(&move);
		gamestate.round++;
		// while (stop)
		// 	;
	}
	return (0);
}
