/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/10 17:18:19 by juazouz          ###   ########.fr       */
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

/*
**	Defines : board information.
*/

# define CELL_EMPTY 0
# define CELL_P1 1
# define CELL_P2 3
# define CELL_P1_NEW 2
# define CELL_P2_NEW 4

/*
**	Defines : player stages.
*/

# define MODE_INITIAL 0
# define MODE_CONTACT 1
# define MODE_EZPZ 2

/*
**	Types.
*/

typedef struct s_point	t_point;
typedef struct s_fpoint	t_fpoint;
typedef struct s_grid	t_grid;
typedef struct s_piece	t_piece;
typedef struct s_state	t_state;

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

struct	s_point
{
	t_bool	iteration_started;
	int		x;
	int		y;
};

struct	s_state
{
	int		mode;
	int		playerid;
	char	playername[MAX_PLAYER_NAME_LEN];
	t_grid	board;
	t_grid	piece;
	t_grid	priority_map;
};

/*
**	Core.
*/

/*
**	Utils.
*/

int		can_place(t_grid *board, t_grid *piece, t_point *target, int playerid);
t_point	point_add(t_point a, t_point b);
int		point_dist(t_point a, t_point b);
void	point_init(t_point *point);
int		player_has_cell(char cell, int playerid);
int		player_is_enemy(int playerid, int other);

/*
**	Grid
*/

t_bool	grid_init(t_grid *board, int height, int width);
void	grid_free(t_grid *board);
char	get_cell_at(t_grid *grid, t_point point);
void	set_cell_at(t_grid *grid, t_point point, char val);
int		get_next_cell(t_grid *grid, t_point *point);

/*
**	Input.
*/

char	read_char();
t_bool	expect_input_char(char expected);
t_bool	expect_input_str(char *str);
t_bool	expect_input_lineend(void);
t_bool	read_number_n(int n, int *num);
t_bool	read_number(char endchar, int *num);

/*
**	Piece.
*/

void	piece_init(t_piece *piece, int height, int width);
t_point	piece_center(t_grid *piece);
int		piece_in_bounds(t_grid *board, t_grid *piece, t_point point);

/*
**	Parse.
*/

t_bool	read_head(int *id, char *name);
t_bool	parse_board(t_grid *board);
t_bool	parse_piece(t_grid *board);

/*
**	Debug.
*/

void	grid_print(t_grid *board);

/*
**	Move.
*/

int		compute_move(t_state *state, t_point *point);
void	write_move(t_point *move);
int		get_nearest_enemy(t_state *state, t_point start, t_point *found);

#endif
