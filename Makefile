#Variables
COP = g++
FLAGS = -Wall -std=c++11 -g
NAME = main

OBJ = main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(COP) $(FLAGS) -o $(NAME) $(OBJ)

main.o: main.cpp
	$(COP) $(FLAGS) -c main.cpp

clean: 
	rm -f $(OBJ) $(NAME) *.h.gch *.o