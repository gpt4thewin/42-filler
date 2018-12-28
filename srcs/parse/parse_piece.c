/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:45:04 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 15:59:15 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	parse_head(t_grid *board)
{
	int		height;
	int		width;

	expect_input_str("Piece ");
	height = read_number(' ');
	width = read_number(':');
	expect_input_lineend();
	grid_init(board, height, width);
}

static void	parse_line(t_grid *board, int lineno)
{
	int		i;
	char	c;

	i = 0;
	while (i < board->width)
	{
		c = read_char();
		if (c == '.')
			set_cell_at(board, i, lineno, 0);
		else if (c == '*')
			set_cell_at(board, i, lineno, 1);
		else
			error(MSG_PARSE_ERROR);
		i++;
	}
	expect_input_lineend();
}

void		parse_piece(t_grid *board)
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
