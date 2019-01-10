/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:03:28 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/10 17:19:53 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_bool	grid_init(t_grid *grid, int height, int width)
{
	grid->height = height;
	grid->width = width;
	grid->cells = malloc((height * width) * sizeof(*grid->cells));
	if (grid->cells == NULL)
		return (false);
	return (true);
}
