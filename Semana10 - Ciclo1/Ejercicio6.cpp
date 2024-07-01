#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int Validar_N()
{
    int N;
    do
    {
        cout << "Ingrese el valor de N: "; cin >> N;
    } while (N <= 2);
    return N;
}

void Graficando_Cripta(int N, bool* Primos)
{
    for (int i = 0; i < N; i++)
    {
        Primos[i] = true;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (Primos[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                Primos[j] = false;
            }
        }
    }

    cout << endl << "Numeros primos desde 2 hasta " << N << " son :" << endl;
    for (int i = 2; i <= N; i++)
    {
        if (Primos[i])
        {
            cout << i << ' ';
        }
        else
        {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main()
{
    int N = Validar_N();
    bool* Primos = new bool[N + 1];

    Graficando_Cripta(N, Primos);

    delete[] Primos;
    Primos = nullptr;

    system("pause>0");
    return 0;
}