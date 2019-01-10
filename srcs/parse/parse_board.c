/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:03:24 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/10 17:09:15 by juazouz          ###   ########.fr       */
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

static t_bool	parse_head(t_grid *board)
{
	int		width;
	int		height;

	return (expect_input_str("Plateau ") &&
			read_number(' ', &width) &&
			width > 0 &&
			read_number(':', &height) &&
			height > 0 &&
			expect_input_lineend() &&
			grid_init(board, width, height));
}

/*
**	Parses the second line.
*/

static t_bool	parse_grid_head(t_grid *board)
{
	int		i;

	if (!expect_input_str("    "))
		return (false);
	i = 0;
	while (i < board->width)
	{
		if (!expect_input_char((i % 10) + '0'))
			return (false);
		i++;
	}
	if (!expect_input_lineend())
		return (false);
	return (true);
}

static t_bool	parse_line_char(t_grid *board, t_point point, char c)
{
	if (c == '.')
		set_cell_at(board, point, CELL_EMPTY);
	else if (c == 'O')
		set_cell_at(board, point, CELL_P1);
	else if (c == 'o')
		set_cell_at(board, point, CELL_P1_NEW);
	else if (c == 'X')
		set_cell_at(board, point, CELL_P2);
	else if (c == 'x')
		set_cell_at(board, point, CELL_P2_NEW);
	else
		return (false);
	return (true);
}

/*
**	Parses the remaining content lines of the board
**	and fills the board information.
*/

static t_bool	parse_line(t_grid *board, int lineno)
{
	int		input_lineno;
	int		i;
	char	c;
	t_point	point;

	if (!read_number_n(3, &input_lineno) ||
	input_lineno != lineno ||
	!expect_input_str(" "))
		return (false);
	point.y = lineno;
	i = 0;
	while (i < board->width)
	{
		c = read_char();
		point.x = i;
		if (!parse_line_char(board, point, c))
			return (false);
		i++;
	}
	if (!expect_input_lineend())
		return (false);
	return (true);
}

t_bool			parse_board(t_grid *board)
{
	int		i;

	if (!parse_head(board) ||
		!parse_grid_head(board))
		return (false);
	i = 0;
	while (i < board->height)
	{
		if (!parse_line(board, i))
			return (false);
		i++;
	}
	return (true);
}
