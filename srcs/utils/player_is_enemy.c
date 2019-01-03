/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_is_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:59:51 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 19:01:00 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	player_is_enemy(int playerid, int other)
{
	if (playerid == 1)
	{
		return (other == CELL_P2 || other == CELL_P2_NEW);
	}
	if (playerid == 2)
	{
		return (other == CELL_P1 || other == CELL_P1_NEW);
	}
	return (0);
}
