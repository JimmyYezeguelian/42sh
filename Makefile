##
## Makefile for 42sh in /home/guillaume/Coding/42sh
##
## Made by Newton Guillaume
## Login   <Guillaume@epitech.net>
##
## Started on  Wed Apr  2 09:54:51 2014 Newton Guillaume
## Last update Sun May 25 19:09:55 2014 Robin Maronier
##

CC	=	gcc

CFLAGS	= 	-W -Wall -Werror -I./inc/

NAME	= 	42sh

SRCS	= 	src/42sh.c \
		src/echo.c \
		src/main.c \
		src/pipe.c \
		src/alias.c \
		src/my_man.c \
		src/signals.c \
		src/history.c \
		src/tab_env.c \
		src/redirect.c \
		src/unsetenv.c \
		src/epur_str.c \
		src/exec_line.c \
		src/echo_next.c \
		src/util/verif.c \
		src/builtin_cd.c \
		src/other_42sh.c \
		src/struct_env.c \
		src/aff_prompt.c \
		src/setup_exec.c \
		src/conditions.c \
		src/home_modify.c \
		src/double_left.c \
		src/builtin_env.c \
		src/util/getenv.c \
		src/util/strutil.c \
		src/list_builtin.c \
		src/epur_str_next.c \
		src/epur_str_size.c \
		src/util/termutil.c \
		src/util/my_string.c \
		src/epur_str_error.c \
		src/history_option.c \
		src/exec_line_next.c \
		src/double_separator.c \
		src/get_special_char.c \
		src/util/get_next_line.c \
		src/util/str_to_wordtab.c \
		src/get_special_char_next.c

OBJS	= 	$(SRCS:.c=.o)

LIB	=	ncurses

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -l$(LIB)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
