/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:24:10 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 13:37:19 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

#define BUF_SIZE 1

int	main(int ac, char **av)
{
	int		fd;
	int		state;
	char	buf[BUF_SIZE];

	(void)ac;
	(void)av;
	fd = open("dumper.trace", O_WRONLY | O_CREAT);
	if (fd < 0)
	{
		ft_putendl_fd("Dump : Error", STDERR_FILENO);
		return (1);
	}
	while ((state = read(STDIN_FILENO, &buf, BUF_SIZE)) > 0)
	{
		write(fd, buf, state);
	}
	close(fd);
	return (0);
}
