/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:03:24 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 11:39:59 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Plateau 14 30:
**	    012345678901234567890123456789
**	000 ..............................
**	001 ..............................
**	002 ..............................
**	003 ..............................
**	004 ..............................
**	005 ..............................
**	006 ..............................
**	007 ..............................
**	008 ...............O..............
**	009 ..............................
**	010 ..............................
**	011 ..............................
**	012 ..............................
**	013 ..............................
**	Piece 4 7:
**	...*...
**	...*...
**	...*...
**	..***..
*/

/*
**	Parses the first line.
*/

static void	parse_head(t_board *board)
{
	char	*line;
	int		pos;
	int		width;
	int		height;

	pos = 0;
	if (get_next_line(STDIN_FILENO, &line) <= 0)
		error(MSG_READ_ERROR);
	check_read_str("Plateau ", line, &pos);
	width = parse_number(line, &pos);
	check_read_str(" ", line, &pos);
	height = parse_number(line, &pos);
	check_read_str(":", line, &pos);
	board_init(board, width, height);
	free(line);
}

/*
**	Parses the second line.
*/

static void	parse_board_head(t_board *board)
{
	char	*line;
	int		pos;
	int		i;

	if (get_next_line(STDIN_FILENO, &line) <= 0)
		error(MSG_READ_ERROR);
	pos = 0;
	check_read_str("    ", line, &pos);
	i = 0;
	while (line[i + pos])
	{
		if (line[i + pos] != (i % 10) + '0')
			error(MSG_PARSE_ERROR);
		i++;
	}
	if (i != board->width)
		error(MSG_PARSE_ERROR);
	free(line);
}

/*
**	Parses the remaining content lines of the board
**	and fills the board information.
*/

static void	parse_line(t_board *board, int lineno)
{
	char	*line;
	int		pos;
	int		input_lineno;
	int		i;

	pos = 0;
	if (get_next_line(STDIN_FILENO, &line) <= 0)
		error(MSG_READ_ERROR);
	input_lineno = parse_number_n(line, &pos, 3);
	check_eq(input_lineno, lineno, MSG_PARSE_ERROR);
	check_read_str(" ", line, &pos);
	i = 0;
	while (i < board->width)
	{
		if (line[i + pos] == '.')
			set_cell_at(board, i, lineno, 0);
		else if (line[i + pos] == 'O')
			set_cell_at(board, i, lineno, 1);
		else if (line[i + pos] == 'X')
			set_cell_at(board, i, lineno, 2);
		else
			error(MSG_PARSE_ERROR);
		i++;
	}
	if (line[i + pos] != '\0')
		error(MSG_PARSE_ERROR);
}

void		parse_board(t_board *board)
{
	int		i;

	parse_head(board);
	parse_board_head(board);
	i = 0;
	while (i < board->height)
	{
		parse_line(board, i);
		i++;
	}
}
