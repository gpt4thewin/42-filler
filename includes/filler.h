/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 17:38:00 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*
**	Includes.
*/

# include <stdarg.h>
# include "libft.h"

/*
**	Defines.
*/

# define MAX_PLAYER_NAME_LEN	512

# define ERROR_CODE 1
# define MSG_READ_ERROR "Read error"
# define MSG_PARSE_ERROR_HEAD "Parse error (Invalid head)"
# define MSG_PARSE_ERROR "Parse error"
# define MSG_PARSE_ASSERT_ERROR "Parse assert error"

/*
**	Types.
*/

typedef struct s_board	t_board;
typedef struct s_piece	t_piece;
typedef struct s_point	t_point;

struct	s_board
{
	int		height;
	int		width;
	char	*cells;
};

struct	s_piece
{
	int		size;
	char	*cells;
};

/*
**	Core.
*/

void	error(char *msg);

/*
**	Utils.
*/

void	board_free(t_board *board);
void	board_init(t_board *board, int height, int width);
int		can_place(t_board *map, t_board *small, int x, int y);
char	get_cell_at(t_board *board, int x, int y);
void	set_cell_at(t_board *board, int x, int y, char val);
int		in_bounds(t_board *board, int x, int y);

/*
**	Piece.
*/

int		parse_piece(t_piece **piece);

/*
**	Parse.
*/

int		parse_number(char *str, int *pos);
int		parse_number_n(char *str, int *pos, int n);
void	read_head(int *id, char *name);
void	parse_board(t_board *board);

/*
**	Assert.
*/

void	check_input(char *str);
void	check_strncmp(char *s1, char *s2, unsigned int n, char *msg);
void	check_eq(int a, int b, char *msg);
void	check_is_true(int val, char *msg);
void	check_read_str(char *expected, char *str, int *pos);

/*
**	Debug.
*/

void	board_print(t_board *board);

#endif
