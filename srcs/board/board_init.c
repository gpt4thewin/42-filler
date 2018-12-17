/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:03:28 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/17 15:04:34 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	board_init(t_board *board, int height, int width)
{
	board->height = height;
	board->width = width;
	board->cells = malloc((height * width) * sizeof(*board->cells));
}
