# Define el compilador
CXX = g++

# Define las opciones de compilación
CXXFLAGS = -std=c++11 -Wall -I. -Iinclude  # Asegúrate de incluir este cambio si tus .hpp están en un subdirectorio 'include'

# Nombre del ejecutable
TARGET = juego

# Todos los archivos fuente
SRCS = main.cpp

# Objetos generados a partir de los archivos fuente
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto
all: $(TARGET)

# Regla para construir el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para construir los objetos a partir de los fuentes
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Regla para limpiar los archivos compilados y el ejecutable
clean:
	rm -f $(OBJS) $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)
