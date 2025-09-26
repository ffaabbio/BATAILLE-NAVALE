prog :
	gcc src/*.c src/board/*.c src/config/*.c src/display/*.c src/game/*.c -o prog
	./prog