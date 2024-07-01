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

void Mover(char* forma, int* color, int* dy, int* posY, int N)
{
    for (int i = 0; i < N; i++)
    {
        //Mover en el eje Y
        posY[i] += dy[i];

        //Si se sale del borde de la consola(ALTO)
        if (posY[i] + dy[i] > ALTO_CONSOLA)
        {
            //Teletransportamos al inicio
            posY[i] = 0;
            //Nueva Velocidad
            dy[i] = rand() % (3 - 1 + 1) + 1;
            //Nuevo color
            color[i] = rand() % (15 - 1 + 1) + 1;
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
    //Posiciones en X
    int* posX = new int[N];
    //Posiciones en Y
    int* posY = new int[N];
    //Velocidad en Y 
    int* dy = new int[N];
    //Color para los caracteres
    int* color = new int[N];
    //Forma para los caracteres
    char* forma = new char[N];

    Ventana();

    //Inicializamos los Valores
    for (int i = 0; i < N; i++)
    {
        posX[i] = i;
        posY[i] = 0;
        dy[i] = rand() % (3 - 1 + 1) + 1;
        color[i] = rand() % (15 - 1 + 1) + 1;
        forma[i] = '*';
    }

    while (true)
    {
        //Borrar
        Borrar(posX, posY, N);
        //Mover
        Mover(forma, color, dy, posY, N);
        //Dibujar
        Dibujar(forma, color, posX, posY, N);
        _sleep(50);
    }

    delete[] posX;
    delete[] posY;
    delete[] dy;
    delete[] color;
    delete[] forma;

    posX = nullptr;
    posY = nullptr;
    dy = nullptr;
    color = nullptr;
    forma = nullptr;

    system("pause>0");
    return 0;
}