/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:32:25 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/28 15:59:15 by juazouz          ###   ########.fr       */
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
typedef struct s_grid	t_grid;
typedef struct s_piece	t_piece;

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

void	grid_init(t_grid *board, int height, int width);
void	grid_free(t_grid *board);
// int		can_place(t_grid *map, t_grid *small, int x, int y);
char	get_cell_at(t_grid *board, int x, int y);
void	set_cell_at(t_grid *board, int x, int y, char val);
int		in_bounds(t_grid *board, t_grid *piece, int x, int y);
int		get_next_cell(t_grid *board, t_point *point);
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

int		compute_move(t_grid *board, t_grid *piece, t_point *point, int playerid);
void	write_move(t_point *move);

#endif
