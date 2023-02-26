all: hello geom
hello: helloworld.cpp
	g++ -Wall -Werror -o hello helloworld.cpp
geom: GeomApp.cpp
	g++ -Wall -Werror -o geom GeomApp.cpp 
rmgeom:
	rm geom
rmhello:
	rm hello