all: compile link

compile:
	g++ -c sfmltest.cpp -I ./SFML-2.5.1/include -DSFML_STATIC -o ./Executables/main.o
link:
	g++ ./Executables/main.o -o sfml-app -L ./SFML-2.5.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows  -o ./Executables/main.exe
clean:
	rm -f main *.o
