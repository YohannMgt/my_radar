##
## EPITECH PROJECT, 2022
## Epitech
## File description:
## Makefile
##

SRC	=	lib/my/my_getnbr.c	\
		lib/my/my_int_to_str.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_strappend.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strlen.c	\
		src/init/init_aircraft.c	\
		src/init/init_aircraft2.c	\
		src/init/init_game.c	\
		src/init/init_map.c	\
		src/init/init_menu.c	\
		src/init/init_tower.c	\
		src/aircraft_collisions.c	\
		src/aircraft_hitboxes.c	\
		src/aircraft_towers_area.c	\
		src/aircraft.c	\
		src/clean.c	\
		src/events.c	\
		src/fps.c	\
		src/game.c	\
		src/main.c	\
		src/screen_parts.c	\
		src/timer.c	\
		src/tower.c	\

OBJ	=	$(SRC:.c)

NAME	=	my_radar

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system -lm

clean:
	rm $(NAME)

fclean:	clean

re:	fclean all
