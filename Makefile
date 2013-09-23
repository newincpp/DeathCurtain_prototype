SRC		= damncute/Bullet.cpp \
		  damncute/Path.cpp \
		  damncute/Input.cpp \
		  damncute/Environment.cpp \
		  damncute/Core/Core.cpp \
		  src/DisplayManager.cpp \
		  src/main.cpp \
		  src/TestPattern.cpp

NAME		= demo

CXXFLAGS	= -Wall -Wextra -W -g -I./damncute -std=c++0x

LDFLAGS		= `pkg-config sfml-all --libs`

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
	make -B

.PHONY: all clean fclean re

