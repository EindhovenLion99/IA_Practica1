# definimos las siguientes variables:
# C++: indicará el compilador a usar
# C++.FLAGS: indica las opciones del compilador, en este caso -g para depurar.

PROGRAM_NAME = Coche
OBJECTS = src/main.cpp src/Celda.cpp src/Tablero.cpp src/F_heuristica.cpp
C++ = g++
C++.FLAGS = -g

ER:
	$(C++) $(C++.FLAGS) $(OBJECTS) -o $(PROGRAM_NAME)

clean:
	rm $(PROGRAM_NAME)


