#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int Num_Personas()
{
    int N;
    do
    {
        cout << "Ingrese el numero de personas: "; cin >> N;
    } while (N < 1 || N > 100);
    return N;
}

int Generar_Edades(int N, int* Edades)
{
    for (int i = 0; i < N; i++)
    {
        Edades[i] = rand() % 100 + 1;
    }
    return *Edades;
}

void Mostrar_Edades(int N, int* Edades)
{
    cout << endl << "Las edades son: ";
    for (int i = 0; i < N; i++)
    {
        cout << Edades[i] << " ";
    }
}

int Obtener_MenorEdad(int N, int* Edades)
{
    int mn = Edades[0];
    for (int i = 0; i < N; i++)
    {
        mn = min(mn, Edades[i]);
    }
    return mn;
}

int Obtener_LugarArreglo(int N, int* Edades)
{
    int indicemenor = 0;
    for (int i = 0; i < N; i++)
    {
        if (Edades[i] < Edades[indicemenor])
        {
            indicemenor = i;
        }
    }
    return indicemenor;
}

void Mostrar_MenorEdad_PosArreglo(int mn, int indicemenor)
{
    cout << endl << "La menor edad es " << mn << " y su posicion en el arreglo es " << indicemenor + 1;
}

int Calcular_NumPersonas30y50(int N, int* Edades)
{
    int ContPersonas30y50 = 0;
    for (int i = 0; i < N; i++)
    {
        if (Edades[i] >= 30 && Edades[i] <= 50)
        {
            ContPersonas30y50++;
        }
    }
    return ContPersonas30y50;
}

void Mostrar_NumPersonas30y50(int personas30y50)
{
    cout << endl << "El numero de personas que tienen entre 30 y 50 years es " << personas30y50 << endl;
}

void Buscar_Edad(int N, int* Edades)
{
    int edadbuscar;
    cout << endl << "Ingrese una edad a buscar: "; cin >> edadbuscar;
    bool encontrado = false;
    for (int i = 0; i < N; i++)
    {
        if (edadbuscar == Edades[i])
        {
            cout << endl << "Se encontro la edad en la posicion " << i + 1;
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        cout << endl << "No se encontro la edad en el arreglo";
    }
}

int main()
{
    srand(time(nullptr));
    int N = Num_Personas();
    int* Edades = new int[N];
    Generar_Edades(N, Edades);
    Mostrar_Edades(N, Edades);

    int mn = Obtener_MenorEdad(N, Edades);
    int indicemenor = Obtener_LugarArreglo(N, Edades);
    Mostrar_MenorEdad_PosArreglo(mn, indicemenor);

    int personas30y50 = Calcular_NumPersonas30y50(N, Edades);
    Mostrar_NumPersonas30y50(personas30y50);

    Buscar_Edad(N, Edades);

    delete[] Edades;
    Edades = nullptr;

    system("pause>0");
    return 0;
}