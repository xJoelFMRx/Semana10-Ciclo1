#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int Cantidad_Pesos()
{
    int CantPesos;
    do
    {
        cout << "Ingrese el numero de clientes: "; cin >> CantPesos;
    } while (CantPesos < 1);
    return CantPesos;
}

void Mostrar_Pesos(int CantPesos, int* Pesos)
{
    for (int i = 0; i < CantPesos; i++)
    {
        cout << "Peso #" << i + 1 << ": "; cin >> Pesos[i];
    }
    cout << endl;
}

double Calcular_PesoProm(int CantPesos, int* Pesos)
{
    double S = 0;
    for (int i = 0; i < CantPesos; i++)
    {
        S += Pesos[i];
    }
    return ((1.0 * S) / CantPesos);
}

int Peso_Mayor(int CantPesos, int* Pesos)
{
    int mx = Pesos[0];
    for (int i = 0; i < CantPesos; i++)
    {
        mx = max(mx, Pesos[i]);
    }
    return mx;
}

int Num_PersonasContexDel(int CantPesos, int* Pesos)
{
    int ContPersonasDel = 0;
    for (int i = 0; i < CantPesos; i++)
    {
        if (Pesos[i] < 53)
        {
            ContPersonasDel++;
        }
    }
    return ContPersonasDel;
}

int Num_PersonasContexMed(int CantPesos, int* Pesos)
{
    int ContPersonasMed = 0;
    for (int i = 0; i < CantPesos; i++)
    {
        if (Pesos[i] >= 53 && Pesos[i] <= 60)
        {
            ContPersonasMed++;
        }
    }
    return ContPersonasMed;
}

int Num_PersonasContexGru(int CantPesos, int* Pesos)
{
    int ContPersonasGru = 0;
    for (int i = 0; i < CantPesos; i++)
    {
        if (Pesos[i] > 60)
        {
            ContPersonasGru++;
        }
    }
    return ContPersonasGru;
}

void Datos_Estadisticos(double pesoprom, int maxpeso, int personascontexdel, int personascontexmed, int personascontexgru)
{
    cout << "El peso promedio es: " << pesoprom;
    cout << endl << "El peso de la persona que pesa mas es: " << maxpeso;
    cout << endl << "El numero de personas cuya contextura es delgada es: " << personascontexdel;
    cout << endl << "El numero de personas cuya contextura es mediana es: " << personascontexmed;
    cout << endl << "El numero de personas cuya contextura es gruesa es: " << personascontexgru;
}

int main()
{
    int CantPesos = Cantidad_Pesos();
    int* Pesos = new int[CantPesos];
    Mostrar_Pesos(CantPesos, Pesos);

    double pesoprom = Calcular_PesoProm(CantPesos, Pesos);
    int maxpeso = Peso_Mayor(CantPesos, Pesos);
    int personascontexdel = Num_PersonasContexDel(CantPesos, Pesos);
    int personascontexmed = Num_PersonasContexMed(CantPesos, Pesos);
    int personascontexgru = Num_PersonasContexGru(CantPesos, Pesos);

    Datos_Estadisticos(pesoprom, maxpeso, personascontexdel, personascontexmed, personascontexgru);

    delete[] Pesos;
    Pesos = nullptr;

    system("pause>0");
    return 0;
}