/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/10 16:55:39 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define ERROR 0x1
#define END 0x2

int			main(void)
{
	t_state		state;
	t_point		move;
	int			status;

	status = 0;
	ft_bzero(&state, sizeof(state));
	read_head(&state.playerid, (char*)&state.playername);
	while (status == 0)
	{
		if (!parse_board(&state.board) ||
			!parse_piece(&state.piece))
			status |= ERROR;
		else if (!compute_move(&state, &move))
		{
			move.x = 0;
			move.y = 0;
			status |= END;
		}
		write_move(&move);
		grid_free(&state.board);
		grid_free(&state.piece);
		if (status & ERROR)
			ft_putendl("Error");
	}
	return (0);
}
