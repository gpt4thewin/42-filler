/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:05:54 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 12:07:53 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// static int	next_cell(t_board *board, int *x, int *y)
// {
// 	(*x)++;

// 	if (*x > board->width)
// 	{
// 		(*y)++;
// 		(*x) = 0;
// 	}
// 	if (*y > board->height)
// 		return (0);
// 	return (1);
// }

// int			can_place(t_board *map, t_board *small, int x, int y)
// {
// 	int	overlap;
// 	int	small_x;
// 	int	small_y;

// 	if (!in_bounds(map, x, y))
// 		return (0);
// 	overlap = 0;
// 	small_x = 0;
// 	small_y = 0;
// 	while (next_cell(small, &small_x, &small_y))
// 	{
// 		if (!in_bounds(map, small_x + x, small_y + y))
// 			continue;
// 	}
// 	return (0);
// }
