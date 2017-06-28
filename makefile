CC = g++ -g
exe_file = 4_assignment
exec_file = debug
all: $(exe_file)
debug: CC += -DDEBUG
debug: $(exe_file)
$(exe_file): cave.o event.o flying.o location.o pokestop.o psychic.o rock.o driver.o pokemon.o world.o trainer.o
	$(CC) cave.o event.o flying.o location.o pokestop.o psychic.o rock.o driver.o pokemon.o world.o trainer.o -o $(exe_file)
cave.o: cave.cpp
	$(CC) -c cave.cpp
event.o: event.cpp
	$(CC) -c event.cpp
flying.o: flying.cpp
	$(CC) -c flying.cpp
location.o: location.cpp
	$(CC) -c location.cpp
pokestop.o: pokestop.cpp
	$(CC) -c pokestop.cpp
psychic.o: psychic.cpp
	$(CC) -c psychic.cpp
rock.o: rock.cpp
	$(CC) -c rock.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
pokemon.o: pokemon.cpp
	$(CC) -c pokemon.cpp
world.o: world.cpp
	$(CC) -c world.cpp
trainer.o: trainer.cpp
	$(CC) -c trainer.cpp
clean:
	rm -f *.out *.o *.h.gch $(exe_file)
