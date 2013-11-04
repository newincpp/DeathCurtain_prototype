# http://scottmcpeak.com/autodepend/autodepend.html <- to manage dependances

EXT		=cpp
SRC		= damncute/Bullet.cpp \
		  damncute/Path.cpp \
		  damncute/Background.cpp \
		  damncute/Core/Core.cpp \
		  damncute/Menu.cpp \
		  damncute/APlayer.cpp \
		  src/DisplayManager.cpp \
		  src/main.cpp src/TestPattern.cpp

NAME		= demo

CXXFLAGS	= -Wall -Wextra -W -I./damncute -I./glm -std=c++0x # -emit-llvm -O4

ifeq ($(OS),Windows_NT)
    error:
    $(info Windows is not yet supported!)
else
	UNAME_S := $(shell uname -s)
    	CXX		= clang++
    	LINKER  	= $(CXX)

	ifeq ($(UNAME_S),Linux)
    		LDFLAGS		= `pkg-config sfml-all --libs` #-flto
	endif
	ifeq ($(UNAME_S),Darwin)
    		CXXFLAGS	+= -stdlib=libc++
		LDFLAGS		= -framework SFML -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -std=c++0x -stdlib=libc++
	endif
endif

OBJS		= $(SRC:.$(EXT)=.o)
	# -include $(OBJS:.o=.d) <-
	RM		= rm -f

all: $(NAME)

# compile and generate dependency info;
# more complicated dependency computation, so all prereqs listed
# will also become command-less, prereq-less targets
#   sed:    strip the target (everything before colon)
#   sed:    remove any continuation backslashes
#   fmt -1: list words one per line
#   sed:    strip leading spaces
#   sed:    add trailing colons
%.o: %.$(EXT)
	$(CXX) -c $(CXXFLAGS) $*.$(EXT) -o $*.o
	$(CXX) -MM $(CXXFLAGS) $*.$(EXT) > $*.d
	@mv -f $*.d $*.d.tmp
	@sed -e 's|.*:|$*.o:|' < $*.d.tmp > $*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	    sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp

$(NAME): $(OBJS)
	$(LINKER) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS) *.swp *~ *#

fclean: clean
	$(RM) $(NAME)

re:
	make -B -j4

.PHONY: all clean fclean re

