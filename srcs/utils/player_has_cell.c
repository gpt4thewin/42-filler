/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_has_cell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:25:43 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 18:29:24 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	player_has_cell(char cell, int playerid)
{
	if (cell == CELL_P1 || cell == CELL_P1_NEW)
		return (playerid == 1);
	if (cell == CELL_P2 || cell == CELL_P2_NEW)
		return (playerid == 2);
	return (0);
}
