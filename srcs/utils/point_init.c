/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:30:10 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 14:30:56 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	point_init(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->iteration_started = 0;
}
