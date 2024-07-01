#include "pch.h"
#include <iostream>
#include <conio.h>
#define ANCHO_CONSOLA 80
#define ALTO_CONSOLA 40

using namespace std;
using namespace System;

void Ventana() {
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

void dibujar(float posX, float posY, int alto, char forma, int color) {
    Console::ForegroundColor = ConsoleColor(color);
    for (int i = 0; i < alto; i++) {
        Console::SetCursorPosition(posX, posY + i); cout << forma;
    }
    Console::ResetColor();
}

void borrar(float posX, float posY, int alto) {
    for (int i = 0; i < alto; i++) {
        Console::SetCursorPosition(posX, posY + i); cout << " ";
    }
}

int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

float randFloat(float min, float max) {
    return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
}

int main() {
    srand(time(nullptr));
    int numFichas = randInt(5, 10);
    float* posX = new float[numFichas];
    float* posY = new float[numFichas];
    float* dx = new float[numFichas];
    float* dy = new float[numFichas];
    int* color = new int[numFichas];
    int* alto = new int[numFichas];
    bool* ocupado = new bool[ANCHO_CONSOLA] {0};
    float* velocidad = new float[numFichas];
    int ancho;
    char forma, tecla;
    bool bajar;

    Ventana();

    // Inicialización
    for (int i = 0; i < numFichas; ++i) {
        alto[i] = randInt(2, 5);
        do {
            posX[i] = randInt(0, ANCHO_CONSOLA - 1);
        } while (ocupado[(int)posX[i]]);
        ocupado[(int)posX[i]] = true;
        posY[i] = 0;
        dx[i] = 0;
        dy[i] = 1;
        velocidad[i] = randFloat(0, 1);
        color[i] = randInt(1, 15);
    }
    ancho = 1; forma = '*';

    for (int i = 0; i < numFichas; i++) {
        bajar = true;
        while (bajar) {
            dx[i] = 0;
            if (_kbhit()) {
                tecla = _getch();
                if (tecla == 75) {
                    dx[i] = -1;
                }
                else if (tecla == 77) {
                    dx[i] = 1;
                }
            }

            borrar(posX[i], posY[i], alto[i]);
            posY[i] += dy[i] * velocidad[i];
            if (posX[i] + dx[i] < ANCHO_CONSOLA && posX[i] + dx[i] + ancho >= 0) {
                posX[i] += dx[i];
            }
            dibujar(posX[i], posY[i], alto[i], forma, color[i]);
            if (posY[i] + alto[i] >= ALTO_CONSOLA) {
                bajar = false;
            }
            _sleep(100);
        }
    }

    delete[] posY;
    delete[] posX;
    delete[] dy;
    delete[] dx;
    delete[] color;
    delete[] ocupado;
    delete[] alto;
    delete[] velocidad;

    posY = nullptr;
    posX = nullptr;
    dy = nullptr;
    dx = nullptr;
    color = nullptr;
    ocupado = nullptr;
    alto = nullptr;
    velocidad = nullptr;

    system("pause>0");
    return 0;
}