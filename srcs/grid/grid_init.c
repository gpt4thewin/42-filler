/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:03:28 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 15:56:49 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	grid_init(t_grid *grid, int height, int width)
{
	grid->height = height;
	grid->width = width;
	grid->cells = malloc((height * width) * sizeof(*grid->cells));
}
