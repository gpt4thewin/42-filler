/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 18:38:42 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int argc, char *argv[])
{
	t_state		state;
	t_point		move;
	t_bool		end;

	(void)argc;
	(void)argv;
	end = false;
	ft_bzero(&state, sizeof(state));
	read_head(&state.playerid, (char*)&state.playername);
	while (!end)
	{
		parse_board(&state.board);
		parse_piece(&state.piece);
		if (!compute_move(&state, &move))
		{
			move.x = 0;
			move.y = 0;
			end = true;
		}
		write_move(&move);
		grid_free(&state.board);
		grid_free(&state.piece);
	}
	return (0);
}
