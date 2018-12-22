# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/17 17:47:32 by juazouz           #+#    #+#              #
#    Updated: 2018/12/19 17:40:17 by juazouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I $(LIBFTIDIR) -g

IDIR = includes
SDIR = srcs
ODIR = obj
LIBFTDIR = libft
LIBFTIDIR = $(LIBFTDIR)/includes
LIBFT = libft.a

NAME = filler

DEPS = $(IDIR)/filler.h

OBJ = $(patsubst %.c,$(ODIR)/%.o,$(_SRC)) \
		$(LIBFTDIR)/$(LIBFT)

SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

_SRC =	board/board_free.c \
		board/board_init.c \
		board/can_place.c \
		board/in_bounds.c \
		board/get_cell_at.c \
		board/set_cell_at.c \
		board/board_print.c \
		board/get_next_cell.c \
		error.c \
		main.c \
		parse/read_head.c \
		utils/check_eq.c \
		utils/check_is_true.c \
		utils/check_strncmp.c \
		utils/check_read_str.c \
		utils/check_str_end.c \
		utils/read_next_line.c \
		parse/parse_board.c \
		parse/parse_number.c \
		parse/parse_number_n.c \
		parse/parse_piece.c \
		parse/read_head.c \
		move/compute_move.c \
		move/write_move.c \
		input/expect_input_char.c \
		input/expect_input_lineend.c \
		input/expect_input_str.c \
		input/read_char.c \
		input/read_number.c \
		input/read_number_n.c

.PHONY: all clean fclean re

all: $(NAME) dumper

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

dumper: $(SDIR)/dumper.c $(LIBFTDIR)/$(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFTDIR)/$(LIBFT):
	make -C $(LIBFTDIR)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re:	fclean all
