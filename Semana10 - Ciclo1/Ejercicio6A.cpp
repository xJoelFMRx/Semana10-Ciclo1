#include "pch.h"
#include "iostream"
#include "conio.h"
#define ANCHO_CONSOLA 80
#define ALTO_CONSOLA 40
#define IZQUIERDA 75
#define DERECHA 77

using namespace std;
using namespace System;

void Ventana() {
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

int RandInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

float RandFloat(float min, float max) {
    return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
}

void Borrar(float* x, float* y, int* ancho, int numFichas)
{
    for (int i = 0; i < numFichas; i++)
    {
        for (int j = 0; j < ancho[i]; j++)
        {
            Console::SetCursorPosition(x[i] + j, y[i]); cout << " ";
        }
    }
}

void BorrarMov(int x_mov, int y_mov)
{
    Console::SetCursorPosition(x_mov, y_mov); cout << " ";
}

void Mover(float* x, float* y, float* dx, float* dy, float* velocidad, int* alto, int* ancho, int numFichas)
{
    float nx, ny;
    for (int i = 0; i < numFichas; ++i) {
        nx = x[i] + velocidad[i] * dx[i];
        ny = y[i] + velocidad[i] * dy[i];
        if (nx + ancho[i] - 1 >= ANCHO_CONSOLA || nx < 0) dx[i] *= -1;
        if (ny + alto[i] - 1 >= ALTO_CONSOLA || ny < 0) dy[i] *= -1;
        x[i] += velocidad[i] * dx[i];
        y[i] += velocidad[i] * dy[i];
    }
}

void Dibujar(float* x, float* y, char* forma, int* color, int* ancho, int numFichas)
{
    for (int i = 0; i < numFichas; i++)
    {
        Console::ForegroundColor = ConsoleColor(color[i]);
        for (int j = 0; j < ancho[i]; j++)
        {
            Console::SetCursorPosition(x[i] + j, y[i]); cout << forma[i];
        }
        Console::ResetColor();
    }
}

void DibujarMov(char forma_mov, int color_mov, int x_mov, int y_mov)
{
    Console::ForegroundColor = ConsoleColor(color_mov);
    Console::SetCursorPosition(x_mov, y_mov); cout << forma_mov;
    Console::ResetColor();
}

bool Colision(int x1, int y1, int ancho1, int alto1, int x2, int y2, int ancho2, int alto2) {
    if (x2 > x1 + ancho1 - 1) return false;
    if (x1 > x2 + ancho2 - 1) return false;
    if (y2 > y1 + alto1 - 1) return false;
    if (y1 > y2 + alto2 - 1) return false;
    return true;
}

int main() {
    srand(time(nullptr));
    int numFichas = RandInt(3, 6);
    float* x = new float[numFichas];
    float* y = new float[numFichas];
    float* dx = new float[numFichas];
    float* dy = new float[numFichas];
    int* color = new int[numFichas];
    char* forma = new char[numFichas];
    int* ancho = new int[numFichas];
    int* alto = new int[numFichas];
    float* velocidad = new float[numFichas];

    char tecla;

    // Movil
    int x_mov = ANCHO_CONSOLA / 2;
    int y_mov = ALTO_CONSOLA - 1;
    int dx_mov = 0;
    int color_mov = 14;
    char forma_mov = 254;
    bool mover_mov = false;

    //  Direcciones candidatas 
    int candidatos[2] = { 1, -1 };

    // Inicialización
    for (int i = 0; i < numFichas; ++i) {
        ancho[i] = RandInt(2, 5);
        alto[i] = 1;
        forma[i] = '*';
        x[i] = RandInt(0, ANCHO_CONSOLA - ancho[i]);
        y[i] = RandInt(0, ALTO_CONSOLA - alto[i]);
        dx[i] = candidatos[RandInt(0, 1)]; // 1, -1, 1, -1
        dy[i] = candidatos[RandInt(0, 1)]; //-1, 1, 1, -1
        velocidad[i] = RandFloat(0.1, 1);
        color[i] = RandInt(1, 15);
    }

    Ventana();
    Dibujar(x, y, forma, color, ancho, numFichas);
    while (true) {
        DibujarMov(forma_mov, color_mov, x_mov, y_mov);
        mover_mov = false;
        if (_kbhit()) {
            tecla = _getch();
            if (tecla == DERECHA) {
                mover_mov = true;
                dx_mov = 1;
            }
            else if (tecla == IZQUIERDA) {
                mover_mov = true;
                dx_mov = -1;
            }
        }

        Borrar(x, y, ancho, numFichas);
        Mover(x, y, dx, dy, velocidad, alto, ancho, numFichas);
        Dibujar(x, y, forma, color, ancho, numFichas);

        if (mover_mov) {
            BorrarMov(x_mov, y_mov);
            if (x_mov + dx_mov < ANCHO_CONSOLA && x_mov + dx_mov >= 0) x_mov += dx_mov;
            //dibujar(x_mov, y_mov, 1, 1, forma_mov, color_mov);
        }

        for (int i = 0; i < numFichas; ++i)
        {
            if (Colision(x[i], y[i], ancho[i], alto[i], x_mov, y_mov, 1, 1))
            {
                dx[i] *= -1;
                dy[i] *= -1;
                if (velocidad[i] < 1)
                    velocidad[i] += 0.1;
            }
        }
        _sleep(10);
    }

    delete[] y;
    delete[] x;
    delete[] dy;
    delete[] dx;
    delete[] color;
    delete[] ancho;
    delete[] velocidad;
    delete[] forma;
    delete[] alto;

    y = nullptr;
    x = nullptr;
    dy = nullptr;
    dx = nullptr;
    color = nullptr;
    ancho = nullptr;
    velocidad = nullptr;
    forma = nullptr;
    alto = nullptr;

    system("pause>0");
    return 0;
}