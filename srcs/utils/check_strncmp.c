/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_strncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:34:23 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 18:34:24 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

/*
**	Asserts that ft_strncmp() returns 0 with the specified parameters.
*/

void	check_strncmp(char *s1, char *s2, unsigned int n, char *msg)
{
	if (ft_strncmp(s1, s2, n) != 0)
		error(msg);
}
