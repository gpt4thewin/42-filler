/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_in_bounds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:22:18 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 17:27:54 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	piece_in_bounds(t_grid *board, t_grid *piece, t_point point)
{
	return (point.x + piece->width <= board->width &&
			point.y + piece->height <= board->height);
}
