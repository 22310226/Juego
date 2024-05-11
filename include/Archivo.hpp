#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>  // Para std::out_of_range

using namespace std;

// Clase base abstracta para personajes
class Personaje {
public:
    string nombre;
    int vida;
    int fuerza;

    Personaje(string nombre, int vida, int fuerza) : nombre(nombre), vida(vida), fuerza(fuerza) {}
    virtual void mostrarInformacion() = 0;  // Método virtual puro
    virtual void moverDerecha() = 0;
    virtual void moverIzquierda() = 0;
    virtual void golpear() = 0;
    virtual void matar() = 0;
};

class Jugador : public Personaje {
public:
    Jugador(string nombre, int vida, int fuerza) : Personaje(nombre, vida, fuerza) {}

    void moverDerecha() override {
        cout << nombre << " se mueve a la derecha.\n";
    }
    void moverIzquierda() override {
        cout << nombre << " se mueve a la izquierda.\n";
    }
    void golpear() override {
        cout << nombre << " golpea.\n";
    }
    void matar() override {
        cout << nombre << " mata a su oponente.\n";
    }
    void mostrarInformacion() override {
        cout << "Jugador: " << nombre << ", Vida: " << vida << ", Fuerza: " << fuerza << endl;
    }
};

class Contrincante : public Personaje {
public:
    Contrincante(string nombre, int vida, int fuerza) : Personaje(nombre, vida, fuerza) {}

    void moverDerecha() override {
        cout << nombre << " se mueve a la derecha.\n";
    }
    void moverIzquierda() override {
        cout << nombre << " se mueve a la izquierda.\n";
    }
    void golpear() override {
        cout << nombre << " golpea.\n";
    }
    void matar() override {
        cout << nombre << " mata a su oponente.\n";
    }
    void mostrarInformacion() override {
        cout << "Contrincante: " << nombre << ", Vida: " << vida << ", Fuerza: " << fuerza << endl;
    }
};

class AdministradorDePersonajes {
private:
    vector<Personaje*> personajes;

public:
    ~AdministradorDePersonajes() {
        for (auto p : personajes) {
            delete p;
        }
    }

    void agregarPersonaje(Personaje* p) {
        personajes.push_back(p);
    }

    Personaje* obtenerPersonaje(int index) {
        if (index >= 0 && index < personajes.size()) {
            return personajes[index];
        } else {
            throw std::out_of_range("Índice de personaje fuera de rango.");
        }
    }

    void mostrarPersonajes() {
        for (auto& p : personajes) {
            p->mostrarInformacion();
        }
    }
};