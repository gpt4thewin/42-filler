/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:36:35 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 18:36:50 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	piece_init(t_piece *piece, int height, int width)
{
	piece->height = height;
	piece->width = width;
	piece->cells = malloc((height * width) * sizeof(*piece->cells));
}
