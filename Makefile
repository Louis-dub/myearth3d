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

CC = clang

CFLAGS_BASE	:=	-Iinclude -g
LDFLAGS_BASE :=	-l csfml-graphics -l csfml-window -lcsfml-system -lcsfml-audio -lm

RM := rm -fr

# Flags par défaut
CFLAGS = $(CFLAGS_BASE)
LDFLAGS = $(LDFLAGS_BASE)

all: $(NAME)

# Cible ASan : on redéfinit explicitement les variables pour cette règle
asan: CFLAGS = $(CFLAGS_BASE) -fsanitize=address
asan: LDFLAGS = $(LDFLAGS_BASE) -fsanitize=address
asan: export LSAN_OPTIONS = use_stacks=0:use_registers=0
asan: clean $(NAME)
	./$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re asan
