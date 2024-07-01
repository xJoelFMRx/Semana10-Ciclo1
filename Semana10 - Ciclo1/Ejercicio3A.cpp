#include "pch.h"
#include "iostream"
#define ANCHO_CONSOLA 80
#define ALTO_CONSOLA 40

using namespace System;
using namespace std;

void Ventana()
{
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

void Borrar(int* posX, int* posY, int N)
{
    for (int i = 0; i < N; i++)
    {
        Console::SetCursorPosition(posX[i], posY[i]); cout << " ";
    }
}

void Mover(int* posY, int* dy, char* forma, int* color, int N)
{
    for (int i = 0; i < N; i++)
    {
        posY[i] += dy[i];

        if (posY[i] + dy[i] > ALTO_CONSOLA)
        {
            //Regresar al inicio
            posY[i] = 0;
            //Nueva velocidad
            dy[i] = rand() % (3 - 1 + 1) + 1;
            //Nuevo color
            color[i] = rand() % (15 - 1 + 1) + 1;
            //Nueva forma
            forma[i] = rand() % ('Z' - 'A' + 1) + 'A';
        }
    }
}

void Dibujar(char* forma, int* color, int* posX, int* posY, int N)
{
    for (int i = 0; i < N; i++)
    {
        Console::ForegroundColor = ConsoleColor(color[i]);
        Console::SetCursorPosition(posX[i], posY[i]); cout << forma[i];
        Console::ResetColor();
    }
}

int main()
{
    srand(time(nullptr));
    int N = ANCHO_CONSOLA;
    int* posX = new int[N];
    int* posY = new int[N];
    int* dy = new int[N];
    char* forma = new char[N];
    int* color = new int[N];

    Ventana();

    //Inicializando los valores
    for (int i = 0; i < N; i++)
    {
        posX[i] = i;
        posY[i] = 0;
        dy[i] = rand() % (3 - 1 + 1) + 1;
        forma[i] = rand() % ('Z' - 'A' + 1) + 'A';
        color[i] = rand() % (15 - 1 + 1) + 1;
    }

    while (true)
    {
        //Borrar
        Borrar(posX, posY, N);
        //Mover
        Mover(posY, dy, forma, color, N);
        //Dibujar
        Dibujar(forma, color, posX, posY, N);
        _sleep(50);
    }

    delete[] posX;
    delete[] posY;
    delete[] dy;
    delete[] forma;
    delete[] color;

    posX = nullptr;
    posY = nullptr;
    dy = nullptr;
    forma = nullptr;
    color = nullptr;

    system("pause>0");
    return 0;
}