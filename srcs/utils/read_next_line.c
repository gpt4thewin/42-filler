/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:05:40 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 14:14:52 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "filler.h"

void	read_next_line(char **line)
{
	if (get_next_line(STDIN_FILENO, line) <= 0)
		error(MSG_READ_ERROR);
}
