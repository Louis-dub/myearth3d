##
## DUBOIS PROJECT, 2026
## myearth
## File description:
## Makefile
##

NAME = my_earth

SRC = $(wildcard src/*.c) \
	  $(wildcard src/init/*.c) \
	  $(wildcard src/free/*.c)

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS	:=	-Iinclude

LDFLAGS	:=	-l csfml-graphics -l csfml-window -lcsfml-system -lcsfml-audio -lm

RM := rm -fr

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re