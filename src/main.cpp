#include "include/Archivo.hpp"
#include <iostream>

int main() {
    AdministradorDePersonajes administradorDePersonajes;

    // Añadiendo personajes al juego
    administradorDePersonajes.agregarPersonaje(new Jugador("Hero", 100, 50));
    administradorDePersonajes.agregarPersonaje(new Contrincante("Villain", 80, 40));

    // Mostrar la información inicial de todos los personajes
    std::cout << "Estado inicial de los personajes:" << std::endl;
    administradorDePersonajes.mostrarPersonajes();

    // Simulación de acciones
    std::cout << "\nSimulación del juego:" << std::endl;
    administradorDePersonajes.obtenerPersonaje(0)->moverDerecha();
    administradorDePersonajes.obtenerPersonaje(1)->moverIzquierda();
    administradorDePersonajes.obtenerPersonaje(0)->golpear();
    administradorDePersonajes.obtenerPersonaje(1)->golpear();

    // Simulación de combate
    administradorDePersonajes.obtenerPersonaje(0)->matar();
    administradorDePersonajes.obtenerPersonaje(1)->matar();

    return 0;
}