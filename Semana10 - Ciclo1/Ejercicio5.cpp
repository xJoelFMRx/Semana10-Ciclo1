#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int Validar_CantidadElementos()
{
    int CantElementos;
    do
    {
        cout << "Ingrese el numero de elementos: "; cin >> CantElementos;
    } while (CantElementos < 1 || CantElementos > 50);
    return CantElementos;
}

int Generar_Numeros(int CantElementos, int* Numeros)
{
    for (int i = 0; i < CantElementos; i++)
    {
        Numeros[i] = rand() % 100 + 1;
    }
    return *Numeros;
}

void Mostrar_Numeros(int CantElementos, int* Numeros)
{
    cout << endl << "Vector: ";
    for (int i = 0; i < CantElementos; i++)
    {
        cout << Numeros[i] << " ";
    }
}

void Mostrar_SecAscendente(int CantElementos, int* Numeros)
{
    cout << endl << "Secuencias Ascendetentes: " << endl;
    cout << Numeros[0] << " ";
    for (int i = 1; i < CantElementos; i++)
    {
        if (Numeros[i - 1] > Numeros[i])
        {
            cout << endl;
        }
        cout << Numeros[i] << " ";
    }
}

int main()
{
    srand(time(nullptr));
    int CantElementos = Validar_CantidadElementos();
    int* Numeros = new int[CantElementos];

    Generar_Numeros(CantElementos, Numeros);
    Mostrar_Numeros(CantElementos, Numeros);

    Mostrar_SecAscendente(CantElementos, Numeros);

    delete[] Numeros;
    Numeros = nullptr;

    system("pause>0");
    return 0;
}