/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/19 17:42:41 by juazouz          ###   ########.fr       */
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
# define ERROR_FD STDERR_FILENO
# define MSG_READ_ERROR "Read error"
# define MSG_PARSE_ERROR_HEAD "Parse error (Invalid head)"
# define MSG_PARSE_ERROR "Parse error"
// # define MSG_PARSE_ASSERT_ERROR "Parse assert error"

/*
**	Types.
*/

typedef struct s_point	t_point;
typedef struct s_board	t_board;
typedef struct s_piece	t_piece;

struct	s_board
{
	int		height;
	int		width;
	char	*cells;
};

struct	s_piece
{
	int		height;
	int		width;
	int		size;
	char	*cells;
};

struct s_point
{
	int		x;
	int		y;
};

/*
**	Core.
*/

void	error(char *msg);

/*
**	Utils.
*/

void	board_init(t_board *board, int height, int width);
void	board_free(t_board *board);
// int		can_place(t_board *map, t_board *small, int x, int y);
char	get_cell_at(t_board *board, int x, int y);
void	set_cell_at(t_board *board, int x, int y, char val);
int		in_bounds(t_board *board, int x, int y);
int		get_next_cell(t_board *board, t_point *point);
void	read_next_line(char **line);

/*
**	Input.
*/

char	read_char();
void	expect_input_char(char expected);
void	expect_input_str(char *str);
void	expect_input_lineend();
int		read_number_n(int n);
int		read_number(char endchar);

/*
**	Piece.
*/

void	piece_init(t_piece *piece, int height, int width);

/*
**	Parse.
*/

void	read_head(int *id, char *name);
void	parse_board(t_board *board);
void	parse_piece(t_board *board);

/*
**	Assert.
*/

void	check_strncmp(char *s1, char *s2, unsigned int n, char *msg);
void	check_eq(int a, int b, char *msg);
void	check_is_true(int val, char *msg);

/*
**	Debug.
*/

void	board_print(t_board *board);

/*
**	Move.
*/

int		compute_move(t_board *board, t_board *piece, t_point *point, int playerid);
void	write_move(t_point *move);

#endif
