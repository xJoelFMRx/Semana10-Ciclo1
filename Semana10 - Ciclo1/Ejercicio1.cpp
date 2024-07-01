#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

void Mostrar_Notas(int CantNotas, int* Notas)
{
    for (int i = 0; i < CantNotas; i++)
    {
        do
        {
            cout << "Nota #" << i + 1 << ": "; cin >> Notas[i];
        } while (Notas[i] < 0 || Notas[i] > 20);
    }
}

int Obtener_MenorNota(int CantNotas, int* Notas)
{
    int mn = Notas[0];
    for (int i = 0; i < CantNotas; i++)
    {
        mn = min(mn, Notas[i]);
    }
    return mn;
}

double Obtener_SumNotas(int CantNotas, int* Notas)
{
    double S = 0;
    for (int i = 0; i < CantNotas; i++)
    {
        S += Notas[i];
    }
    return S;
}

int main()
{
    const int CantNotas = 6;
    int* Notas = new int[CantNotas];

    cout << "\tIngrese las notas: " << endl;
    Mostrar_Notas(CantNotas, Notas);

    int mn = Obtener_MenorNota(CantNotas, Notas);
    cout << endl << "La nota que no se considera en el promedio es " << mn;

    double SumatoriaNotas = Obtener_SumNotas(CantNotas, Notas);
    cout << endl << "El promedio de las notas del alumno es: " << (1.0 * (SumatoriaNotas - mn)) / (CantNotas - 1);

    delete[] Notas;
    Notas = nullptr;

    system("pause>0");
    return 0;
}
