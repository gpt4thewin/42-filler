/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:27:39 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 12:28:36 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	write_move(t_point *move)
{
	ft_putnbr(move->x);
	ft_putchar(' ');
	ft_putnbr(move->y);
	ft_putchar('\n');
}
