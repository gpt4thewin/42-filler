/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_bounds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:22:18 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/17 15:23:08 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	in_bounds(t_board *board, t_board *piece, int x, int y)
{
	return (x + piece->width <= board->width &&
			y + piece->height <= board->height);
}
