#include "pch.h"
#include "iostream"
#define ANCHO_CONSOLA 100
#define ALTO_CONSOLA 40

using namespace System;
using namespace std;

void Ventana()
{
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

void Borrar(int* posX, int* posY, int* ancho, int N)
{
    for (int i = 0; i < N; i++)
    {
        //Borramos la cantidad de asteriscos que tenga el ancho
        for (int j = 0; j < ancho[i]; j++)
        {
            Console::SetCursorPosition(posX[i] + j, posY[i]); cout << " ";
        }
    }
}

void Mover(int* posX, int* posY, int* dy, int* dx, int* alto, int* ancho, int N)
{
    for (int i = 0; i < N; i++)
    {
        posX[i] += dx[i];
        posY[i] += dy[i];

        //Rebotes
        if (posY[i] + dy[i] < 0 || posY[i] + alto[i] + dy[i] > ALTO_CONSOLA)
        {
            dy[i] *= -1;
        }
        if (posX[i] + dx[i] < 0 || posX[i] + ancho[i] + dx[i] > ANCHO_CONSOLA)
        {
            dx[i] *= -1;
        }
    }
}

void Dibujar(char* forma, int* color, int* posX, int* posY, int* ancho, bool* esActivo, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (esActivo[i] == true)
        {
            Console::ForegroundColor = ConsoleColor(color[i]);
            //Imprimimos la cantidad de asteriscos que tenga el ancho
            for (int j = 0; j < ancho[i]; j++)
            {
                Console::SetCursorPosition(posX[i] + j, posY[i]); cout << forma[i];
            }
            Console::ResetColor();
        }
    }
}

void Colision(int* posX, int* posY, int* ancho, int* alto, bool* esActivo, int& contActivos, int N)
{
    for (int i = 0; i < N - 1; i++)//Rojo
    {
        for (int j = i + 1; j < N; j++)//Celeste
        {
            //Hay colision y elimina las figuras
            if (!(posY[i] + alto[i] < posY[j] || posY[i] > posY[j] + alto[j] || posX[i] > posX[j] + ancho[j] || posX[i] + ancho[i] < posX[j]) && esActivo[i] == true && esActivo[j] == true)
            {
                esActivo[i] = false;
                esActivo[j] = false;
                contActivos -= 2;
                //El break es para que no se desactive mas de una vez
                //En caso el de rojo colisione con uno de celeste se supone que ya no debe verificar con otros por eso 
                //el bucle debe terminar, es decir break
                break;
            }
        }
    }
}

int main()
{
    srand(time(nullptr));
    int N = rand() % (10 - 5 + 1) + 5;
    int contActivos = N;
    int* posX = new int[N];
    int* posY = new int[N];
    int* dx = new int[N];
    int* dy = new int[N];
    int* color = new int[N];
    int* alto = new int[N];
    int* ancho = new int[N];
    char* forma = new char[N];
    bool* esActivo = new bool[N];

    Ventana();

    //Inicializando valores
    for (int i = 0; i < N; i++)
    {
        ancho[i] = rand() % (5 - 2 + 1) + 2;
        alto[i] = 1;
        posX[i] = rand() % ((ANCHO_CONSOLA - ancho[i]) - 0 + 1) + 0;
        posY[i] = rand() % ((ALTO_CONSOLA - alto[i]) - 0 + 1) + 0;
        dx[i] = 1;
        dy[i] = 1;
        color[i] = rand() % (15 - 1 + 1) + 1;
        forma[i] = '*';
        esActivo[i] = true;
    }

    //Usamos do-while porque tenemos una condicion en el problema
    do
    {
        //Borrar
        Borrar(posX, posY, ancho, N);
        //Colision
        Colision(posX, posY, ancho, alto, esActivo, contActivos, N);
        //Mover
        Mover(posX, posY, dy, dx, alto, ancho, N);
        //Dibujar
        Dibujar(forma, color, posX, posY, ancho, esActivo, N);
        _sleep(50);
    } while (contActivos > 2);

    delete[] posX;
    delete[] posY;
    delete[] dx;
    delete[] dy;
    delete[] color;
    delete[] alto;
    delete[] ancho;
    delete[] forma;
    delete[] esActivo;

    posX = nullptr;
    posY = nullptr;
    dx = nullptr;
    dy = nullptr;
    color = nullptr;
    alto = nullptr;
    ancho = nullptr;
    forma = nullptr;
    esActivo = nullptr;

    return 0;
}