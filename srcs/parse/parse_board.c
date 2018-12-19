/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:03:24 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 17:33:35 by juazouz          ###   ########.fr       */
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
	int		width;
	int		height;

	expect_input_str("Plateau ");
	width = read_number(' ');
	height = read_number(':');
	expect_input_lineend();
	board_init(board, width, height);
}

/*
**	Parses the second line.
*/

static void	parse_board_head(t_board *board)
{
	int		i;

	expect_input_str("    ");
	i = 0;
	while (i < board->width)
	{
		expect_input_char((i % 10) + '0');
		i++;
	}
	expect_input_lineend();
}

/*
**	Parses the remaining content lines of the board
**	and fills the board information.
*/

static void	parse_line(t_board *board, int lineno)
{
	int		input_lineno;
	int		i;
	char	c;

	input_lineno = read_number_n(3);
	check_eq(input_lineno, lineno, MSG_PARSE_ERROR);
	expect_input_str(" ");
	i = 0;
	while (i < board->width)
	{
		c = read_char();
		if (c == '.')
			set_cell_at(board, i, lineno, 0);
		else if (c == 'O' || c == 'o')
			set_cell_at(board, i, lineno, 1);
		else if (c == 'X' || c == 'x')
			set_cell_at(board, i, lineno, 2);
		else
			error(MSG_PARSE_ERROR);
		i++;
	}
	expect_input_lineend();
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
