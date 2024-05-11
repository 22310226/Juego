#pragma once
#include <string>
#include <list>
#include <iostream>
#include <ftxui/screen/screen.hpp>  

using namespace std;
using namespace ftxui;

class Dibujo {
private:
    int posicionX = 0;
    int posicionY = 0;
    list<string> contenido;

public:
    Dibujo() = default;
    Dibujo(int posX, int posY) : posicionX(posX), posicionY(posY) {}
    Dibujo(const string& palabra, int posX, int posY) : posicionX(posX), posicionY(posY), contenido({palabra}) {}

    void Dibujar(Screen& pantalla) {
        int x = posicionX;
        int y = posicionY;
        for (const auto& linea : contenido) {
            for (char letra : linea) {
                if (x < pantalla.dimx() && y < pantalla.dimy()) {
                    pantalla.At(x, y) = Pixel(letra);
                }
                ++x;
            }
            x = posicionX;
            ++y;
        }
        pantalla.Print();
        cout << pantalla.ToString() << endl;
    }
};
