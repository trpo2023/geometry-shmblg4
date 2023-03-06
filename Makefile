all: geom

geom: GeomApp.cpp
	g++ -Wall -Werror -o geom GeomApp.cpp 

clean:
	rm geom