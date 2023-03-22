CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
LIB = -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:Sokoban main.o sokoban.o lint

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<


Sokoban: main.o sokoban.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIB)
lint:
	cpplint --filter=-build/include_subdir,-runtime/references,-runtime/string,-build/c++11 --root=. *
clean:
	rm *.o Sokoban