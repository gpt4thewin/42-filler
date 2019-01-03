/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_center.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:41:23 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 17:16:33 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	piece_center(t_grid *piece)
{
	t_point		res;
	t_point		point;
	int			n;
	char		val;

	n = 0;
	point_init(&res);
	point_init(&point);
	while (get_next_cell(piece, &point))
	{
		val = get_cell_at(piece, point);
		if (val == 1)
		{
			res.x += point.x;
			res.y += point.y;
			n++;
		}
	}
	res.x /= n;
	res.y /= n;

	return (res);
}
