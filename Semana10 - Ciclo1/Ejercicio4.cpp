#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int Validar_NumPernos()
{
    int CantPernos;
    do
    {
        cout << "Ingrese el numero de pernos a analizar: "; cin >> CantPernos;
    } while (CantPernos < 1 || CantPernos > 100);
    return CantPernos;
}

double RandDouble(double min, double max)
{
    return min + (double)(rand()) / RAND_MAX * (max - min);
}

double* Calcular_Diametro_Pernos(int CantPernos)
{
    double* DiamPernos = new double[CantPernos];
    for (int i = 0; i < CantPernos; i++)
    {
        DiamPernos[i] = RandDouble(5.0, 30.0);
    }
    return DiamPernos;
    delete[] DiamPernos;
}

void Mostrar_DiamPernos(int CantPernos, double* DiamPernos)
{
    cout << endl << "Los diametros son: " << endl;
    for (int i = 0; i < CantPernos; i++)
    {
        cout << DiamPernos[i] << " ";
    }
    cout << endl;
}

void Mostrar_DiamPernos_Decreciente(int CantPernos, double* DiamPernos)
{
    cout << endl << "Los diametros ordenados descendentemente: " << endl;
    for (int i = 0; i < CantPernos; i++)
    {
        cout << DiamPernos[i] << " ";
    }
    cout << endl;
}

void Ordenar_Decreciente(int CantPernos, double* DiamPernos)
{
    for (int i = 0; i < CantPernos - 1; i++)
    {
        for (int j = i + 1; j < CantPernos; j++)
        {
            if (DiamPernos[i] < DiamPernos[j])
            {
                double temp = DiamPernos[i];
                DiamPernos[i] = DiamPernos[j];
                DiamPernos[j] = temp;
            }
        }
    }
}

double Obtener_Promedio(int CantPernos, double* DiamPernos)
{
    double S = 0;
    for (int i = 0; i < CantPernos; i++)
    {
        S += DiamPernos[i];
    }
    return (1.0 * S) / CantPernos;
}

void Mostrar_DiametroProm(double DiamPromedio)
{
    cout << endl << "El diametro promedio es: " << DiamPromedio << endl;
}

void SolicitarDE(int CantPernos, double* DiamPernos)
{
    double DE;
    int diametroinfe = 0;
    cout << endl << "Ingrese un diametro: "; cin >> DE;
    for (int i = 0; i < CantPernos; i++)
    {
        if (DiamPernos[i] < DE)
        {
            diametroinfe++;
        }
    }
    cout << endl << diametroinfe << " pernos tienen un diametro inferior al ingresado";
    if (diametroinfe > CantPernos * 0.5)
    {
        cout << endl << "Lote defectuoso";
    }
}

int main()
{
    srand(time(nullptr));
    int CantPernos = Validar_NumPernos();
    double* DiamPernos = Calcular_Diametro_Pernos(CantPernos);

    Mostrar_DiamPernos(CantPernos, DiamPernos);

    Ordenar_Decreciente(CantPernos, DiamPernos);
    Mostrar_DiamPernos_Decreciente(CantPernos, DiamPernos);

    double DiamPromedio = Obtener_Promedio(CantPernos, DiamPernos);
    Mostrar_DiametroProm(DiamPromedio);

    SolicitarDE(CantPernos, DiamPernos);

    delete[] DiamPernos;
    DiamPernos = nullptr;

    system("pause>0");
    return 0;
}