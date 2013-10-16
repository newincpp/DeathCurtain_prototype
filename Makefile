SRC		= damncute/Bullet.cpp \
		  damncute/Path.cpp \
		  damncute/Input.cpp \
		  damncute/Background.cpp \
		  damncute/Core/Core.cpp \
		  damncute/Menu.cpp \
		  damncute/APlayer.cpp \
		  src/DisplayManager.cpp \
		  src/main.cpp \
		  src/TestPattern.cpp

NAME		= demo

CXXFLAGS	= -Wall -Wextra -W -g -I./damncute -I./glm -std=c++0x

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS		= `pkg-config sfml-all --libs`
endif

ifeq ($(UNAME_S),Darwin)
	CXXFLAGS	+= -stdlib=libc++
	LDFLAGS		= -framework SFML -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -std=c++0x -stdlib=libc++
endif

OBJ		= $(SRC:.cpp=.o)

RM		= rm -f

CXX		= clang++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)
clean:
	$(RM) $(OBJ) *.swp *~ *#

fclean: clean
	$(RM) $(NAME)

re:
	make -B -j4

.PHONY: all clean fclean re

