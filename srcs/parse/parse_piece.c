/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:45:04 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 14:08:08 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	parse_head(t_board *board)
{
	char	*line;
	int		pos;
	int		height;
	int		width;

	read_next_line(&line);
	pos = 0;
	check_read_str("Piece ", line, &pos);
	height = parse_number(line, &pos);
	check_read_str(" ", line, &pos);
	width = parse_number(line, &pos);
	check_read_str(":", line, &pos);
	check_str_end(line, &pos);
	board_init(board, height, width);
	free(line);
}

static void	parse_line(t_board *board, int lineno)
{
	char	*line;
	int		i;

	read_next_line(&line);
	i = 0;
	while (i < board->width)
	{
		if (line[i] == '.')
			set_cell_at(board, i, lineno, 0);
		else if (line[i] == '*')
			set_cell_at(board, i, lineno, 1);
		else
			error(MSG_PARSE_ERROR);
		i++;
	}
	check_str_end(line, &i);
	free(line);
}

void		parse_piece(t_board *board)
{
	int	i;

	parse_head(board);
	i = 0;
	while (i < board->height)
	{
		parse_line(board, i);
		i++;
	}
}
