prog : src/*.c src/*/*.c
	gcc -o prog src/*.c src/*/*.c
	./prog