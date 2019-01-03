/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/03 17:30:36 by juazouz          ###   ########.fr       */
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
**	Defines : board information.
*/

# define CELL_EMPTY 0
# define CELL_P1 1
# define CELL_P2 3
# define CELL_P1_NEW 2
# define CELL_P2_NEW 4

/*
**	Types.
*/

typedef struct s_point	t_point;
typedef struct s_fpoint	t_fpoint;
typedef struct s_grid	t_grid;
typedef struct s_piece	t_piece;
typedef struct s_gamestate	t_gamestate;

struct	s_grid
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
	t_bool	iteration_started;
	int		x;
	int		y;
};

struct	s_gamestate
{
	int		round;
	int		playerid;
	char	playername[MAX_PLAYER_NAME_LEN];
	t_grid	board;
	t_grid	piece;
	t_grid	priority_map;
};

/*
**	Core.
*/

void	error(char *msg);

/*
**	Utils.
*/

void	grid_init(t_grid *board, int height, int width);
void	grid_free(t_grid *board);
int		can_place(t_grid *board, t_grid *piece, t_point *target, int playerid);
char	get_cell_at(t_grid *grid, t_point point);
void	set_cell_at(t_grid *grid, t_point point, char val);
int		piece_in_bounds(t_grid *board, t_grid *piece, t_point point);
int		get_next_cell(t_grid *board, t_point *point);
void	read_next_line(char **line);
t_point	point_add(t_point a, t_point b);
int		point_dist(t_point a, t_point b);
void	point_init(t_point *point);
t_point	piece_center(t_grid *piece);
int		player_has_cell(char cell, int playerid);
int		player_is_enemy(int playerid, int other);

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
void	parse_board(t_grid *board);
void	parse_piece(t_grid *board);

/*
**	Assert.
*/

void	check_strncmp(char *s1, char *s2, unsigned int n, char *msg);
void	check_eq(int a, int b, char *msg);
void	check_is_true(int val, char *msg);

/*
**	Debug.
*/

void	grid_print(t_grid *board);

/*
**	Move.
*/

int		compute_move(t_gamestate *gamestate, t_point *point);
void	write_move(t_point *move);
int		get_nearest_enemy(t_gamestate *gamestate, t_point start, t_point *found);

#endif
