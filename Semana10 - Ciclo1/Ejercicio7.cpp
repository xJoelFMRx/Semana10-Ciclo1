#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int Validar_LongMensaje()
{
    int LongitudMens;
    do
    {
        cout << "Ingrese la longitud del mensaje: "; cin >> LongitudMens;
    } while (LongitudMens < 1);
    return LongitudMens;
}

char* Ingresar_Mensaje(int TamañoMensaje)
{
    char* Mensaje = new char[TamañoMensaje];
    for (int i = 0; i < TamañoMensaje; i++)
    {
        cout << "Ingrese caracter #" << i + 1 << ": "; cin >> Mensaje[i];
    }
    return Mensaje;
    delete[] Mensaje;
}

int Obtener_Valor(int TamañoMensaje, char* Mensaje)
{
    int valor = 0;
    for (int i = 0; i < TamañoMensaje; i++)
    {
        if (Mensaje[i] == ' ')
        {
            continue;
        }
        if (isdigit(Mensaje[i]))
        {
            valor += 20;
        }
        else if (isalpha(Mensaje[i]))
        {
            // Considerar letras con tilde y la 'ñ' como caracteres especiales
            if (Mensaje[i] == 'ñ' || Mensaje[i] == 'á' || Mensaje[i] == 'é' || Mensaje[i] == 'í' || Mensaje[i] == 'ó' || Mensaje[i] == 'ú' || Mensaje[i] == 'Ñ' || Mensaje[i] == 'Á' || Mensaje[i] == 'É' || Mensaje[i] == 'Í' || Mensaje[i] == 'Ó' || Mensaje[i] == 'Ú')
            {
                valor += 30;
            }
            else
            {
                valor += 10;
            }
        }
        else
        {
            valor += 30;
        }
    }
    return valor;
}

int main()
{
    int TamañoMensaje = Validar_LongMensaje();
    char* Mensaje = Ingresar_Mensaje(TamañoMensaje);

    cout << endl << "Valor del mensaje: " << Obtener_Valor(TamañoMensaje, Mensaje);

    delete[] Mensaje;
    Mensaje = nullptr;

    system("pause>0");
    return 0;
}