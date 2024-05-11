#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Clase base abstracta para personajes
class Personaje {
public:
    string nombre;
    int vida;
    int fuerza;

    Personaje(string nombre, int vida, int fuerza) : nombre(nombre), vida(vida), fuerza(fuerza) {}
    virtual void mostrarInformacion() = 0;  // Método virtual puro
};

class Jugador : public Personaje {
public:
    Jugador(string nombre, int vida, int fuerza) : Personaje(nombre, vida, fuerza) {}

    void moverDerecha() {
        cout << nombre << " se mueve a la derecha.\n";
    }
    void moverIzquierda() {
        cout << nombre << " se mueve a la izquierda.\n";
    }
    void golpear() {
        cout << nombre << " golpea.\n";
    }
    void matar() {
        cout << nombre << " mata a su oponente.\n";
    }
    void mostrarInformacion() override {
        cout << "Jugador: " << nombre << ", Vida: " << vida << ", Fuerza: " << fuerza << endl;
    }
};

class Contrincante : public Personaje {
public:
    Contrincante(string nombre, int vida, int fuerza) : Personaje(nombre, vida, fuerza) {}

    void moverDerecha() {
        cout << nombre << " se mueve a la derecha.\n";
    }
    void moverIzquierda() {
        cout << nombre << " se mueve a la izquierda.\n";
    }
    void golpear() {
        cout << nombre << " golpea.\n";
    }
    void matar() {
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

    void cargarPersonajes(string path) {
        ifstream archivo(path);
        string tipo, nombre, linea;
        int vida, fuerza;

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            getline(ss, tipo, ',');
            getline(ss, nombre, ',');
            ss >> vida;
            ss.ignore();  // Ignorar la coma
            ss >> fuerza;

            if (tipo == "Jugador") {
                personajes.push_back(new Jugador(nombre, vida, fuerza));
            } else if (tipo == "Contrincante") {
                personajes.push_back(new Contrincante(nombre, vida, fuerza));
            }
        }
    }

    void mostrarPersonajes() {
        for (auto& p : personajes) {
            p->mostrarInformacion();
        }
    }
};

int main() {
    AdministradorDePersonajes administradorDePersonajes;
    administradorDePersonajes.cargarPersonajes("personajes.txt");
    administradorDePersonajes.mostrarPersonajes();
    return 0;
}