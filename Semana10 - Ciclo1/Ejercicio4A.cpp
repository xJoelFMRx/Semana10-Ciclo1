#include "pch.h"
#include "iostream"
#include "conio.h"
#define ANCHO_CONSOLA 120
#define ALTO_CONSOLA 40
#define N 7

using namespace System;
using namespace std;

void Ventana()
{
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

void Borrar(int* posX, int* posY)
{
    for (int i = 0; i < N; i++)
    {
        Console::SetCursorPosition(posX[i], posY[i]); cout << " ";
    }
}

void Mover(char* forma, int* color, int* dy, int* posY, int* posX, int* alto, int* ancho)
{
    for (int i = 0; i < N; i++)
    {
        //Mover en el eje Y
        posY[i] += dy[i];

        //Si se sale del borde de la consola(ALTO)
        if (posY[i] + dy[i] + alto[i] > ALTO_CONSOLA)
        {
            //Nueva posicion en X
            posX[i] = rand() % ((ANCHO_CONSOLA - ancho[i]) - 0 + 1) + 0;
            //Teletransportamos al inicio
            posY[i] = 0;
            //Nueva Velocidad
            dy[i] = rand() % (3 - 1 + 1) + 1;
            //Nuevo color
            color[i] = rand() % (15 - 1 + 1) + 1;
            //Nueva forma
            forma[i] = rand() % ('Z' - 'A' + 1) + 'A';
        }
    }
}

void Dibujar(char* forma, int* color, int* posX, int* posY)
{
    for (int i = 0; i < N; i++)
    {
        Console::ForegroundColor = ConsoleColor(color[i]);
        Console::SetCursorPosition(posX[i], posY[i]); cout << forma[i];
        Console::ResetColor();
    }
}

void BorrarJugador(int posXjugador, int posYjugador)
{
    Console::SetCursorPosition(posXjugador, posYjugador); cout << " ";
}

void MoverJugador(int& posXjugador, int& posYjugador, int dxJugador, int anchoJugador, int altoJugador)
{
    char tecla;
    if (_kbhit())
    {
        tecla = _getch();
        switch (tecla)
        {
            //Flecha izquiera
        case 75:
            if (posXjugador - dxJugador > 0)
            {
                posXjugador -= dxJugador;
            }
            break;
            //Flecha izquiera
        case 77:
            if (posXjugador + dxJugador + anchoJugador < ANCHO_CONSOLA)
            {
                posXjugador += dxJugador;
            }
            break;
        }
    }
}

void DibujarJugador(char formaJugador, int colorJugador, int posXjugador, int posYjugador)
{
    Console::ForegroundColor = ConsoleColor(colorJugador);
    Console::SetCursorPosition(posXjugador, posYjugador); cout << formaJugador;
    Console::ResetColor();
}

void Colision(int* posX, int* posY, int* ancho, int* alto, int posXjugador, int posYjugador, int anchoJugador, int altoJugador, int& vidas)
{
    for (int i = 0; i < N - 1; i++)//i -> gotas
    {
        if (!(posY[i] + alto[i] < posYjugador || posY[i] > posYjugador + altoJugador || posX[i] > posXjugador + anchoJugador || posX[i] + ancho[i] < posXjugador))
        {
            //Hay colision
            vidas--;
            break;
        }
    }
}

void DibujarCorazones(int vidas)
{
    Console::SetCursorPosition(0, 0); cout << vidas << ":";
    for (int i = 2; i <= vidas + 1; i++)
    {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(i, 0); cout << (char)3;
        Console::ResetColor();
    }
}

void BorrarCorazones(int vidas)
{
    for (int i = 2; i <= vidas + 1; i++)
    {
        Console::SetCursorPosition(i, 0); cout << " ";
    }
}

int main()
{
    srand(time(nullptr));
    //Posiciones en X
    int* posX = new int[N];
    //Posiciones en Y
    int* posY = new int[N];
    //Velocidad en Y 
    int* dy = new int[N];
    //Ancho 
    int* ancho = new int[N];
    //Alto
    int* alto = new int[N];
    //Color para los caracteres
    int* color = new int[N];
    //Forma para los caracteres
    char* forma = new char[N];

    //Inicializamos valores Jugador
    int altoJugador = 1;
    int anchoJugador = 1;
    int posYjugador = ALTO_CONSOLA - altoJugador;
    int posXjugador = (ANCHO_CONSOLA * anchoJugador) / 2;
    int dxJugador = 1;
    int colorJugador = 14;
    char formaJugador = 254;
    int vidas = 8;

    //Inicializamos los valores Lluvia
    for (int i = 0; i < N; i++)
    {
        ancho[i] = 1;
        alto[i] = 1;
        posX[i] = rand() % ((ANCHO_CONSOLA - ancho[i]) - 0 + 1) + 0;
        posY[i] = 0;
        dy[i] = rand() % (3 - 1 + 1) + 1;
        color[i] = rand() % (15 - 1 + 1) + 1;
        forma[i] = rand() % ('Z' - 'A' + 1) + 'A';
    }

    Ventana();

    do
    {
        //Borrar
        Borrar(posX, posY);
        BorrarJugador(posXjugador, posYjugador);
        BorrarCorazones(vidas);
        //Colision
        Colision(posX, posY, ancho, alto, posXjugador, posYjugador, anchoJugador, altoJugador, vidas);
        //Mover
        Mover(forma, color, dy, posY, posX, alto, ancho);
        MoverJugador(posXjugador, posYjugador, dxJugador, anchoJugador, altoJugador);
        //Dibujar
        Dibujar(forma, color, posX, posY);
        DibujarJugador(formaJugador, colorJugador, posXjugador, posYjugador);
        DibujarCorazones(vidas);
        _sleep(1);
    } while (vidas > 0);

    delete[] posX;
    delete[] posY;
    delete[] dy;
    delete[] color;
    delete[] forma;
    delete[] alto;
    delete[] ancho;

    posX = nullptr;
    posY = nullptr;
    dy = nullptr;
    color = nullptr;
    forma = nullptr;
    ancho = nullptr;
    alto = nullptr;

    return 0;
}