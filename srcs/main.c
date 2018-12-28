/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 15:59:15 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int argc, char *argv[])
{
	int		playerid;
	char	playername[MAX_PLAYER_NAME_LEN];
	t_grid	board;
	t_grid	piece;
	t_point	move;
	// int		stop = 1;

	(void)argc;
	(void)argv;
	ft_bzero(&piece, sizeof(piece));
	read_head(&playerid, (char*)&playername);
	while (1)
	{
		parse_board(&board);
		parse_piece(&piece);
		// grid_print(&board);
		// grid_print(&piece);
		if (!compute_move(&board, &piece, &move, playerid))
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
