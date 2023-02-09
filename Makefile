all:
	g++ -Iinclude/SDL2 -Llib -o main *.cpp -lmingw32 -lSDl2main -lSDL2 -lSDL2_image