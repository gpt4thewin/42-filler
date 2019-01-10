/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:45:04 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/10 16:09:23 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_bool	parse_head(t_grid *board)
{
	int		height;
	int		width;

	return (expect_input_str("Piece ") &&
			read_number(' ', &height) &&
			read_number(':', &width) &&
			expect_input_lineend() &&
			grid_init(board, height, width));
}

static t_bool	parse_line(t_grid *board, int lineno)
{
	int		i;
	char	c;
	t_point	point;

	point.y = lineno;
	i = 0;
	while (i < board->width)
	{
		point.x = i;
		c = read_char();
		if (c == '.')
			set_cell_at(board, point, 0);
		else if (c == '*')
			set_cell_at(board, point, 1);
		else
			return (false);
		i++;
	}
	if (!expect_input_lineend())
		return (false);
	return (true);
}

t_bool			parse_piece(t_grid *board)
{
	int	i;

	if (!parse_head(board))
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
