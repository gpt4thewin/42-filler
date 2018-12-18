/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 13:30:25 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int argc, char *argv[])
{
	int		playerid;
	char	playername[MAX_PLAYER_NAME_LEN];
	t_board	board;
	t_piece	*piece;

	(void)argc;
	(void)argv;
	ft_bzero(&piece, sizeof(piece));
	read_head(&playerid, (char*)&playername);
	parse_board(&board);
	board_print(&board);
	// while (1)
	// {
	// 	if (!read_state(&piece))
	// 		break ;
	// 	free_piece(piece);
	// }
	return (0);
}
