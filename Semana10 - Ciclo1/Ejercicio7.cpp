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

char* Ingresar_Mensaje(int Tama�oMensaje)
{
    char* Mensaje = new char[Tama�oMensaje];
    for (int i = 0; i < Tama�oMensaje; i++)
    {
        cout << "Ingrese caracter #" << i + 1 << ": "; cin >> Mensaje[i];
    }
    return Mensaje;
    delete[] Mensaje;
}

int Obtener_Valor(int Tama�oMensaje, char* Mensaje)
{
    int valor = 0;
    for (int i = 0; i < Tama�oMensaje; i++)
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
            // Considerar letras con tilde y la '�' como caracteres especiales
            if (Mensaje[i] == '�' || Mensaje[i] == '�' || Mensaje[i] == '�' || Mensaje[i] == '�' || Mensaje[i] == '�' || Mensaje[i] == '�' || Mensaje[i] == '�' || Mensaje[i] == '�' || Mensaje[i] == '�' || Mensaje[i] == '�' || Mensaje[i] == '�' || Mensaje[i] == '�')
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
    int Tama�oMensaje = Validar_LongMensaje();
    char* Mensaje = Ingresar_Mensaje(Tama�oMensaje);

    cout << endl << "Valor del mensaje: " << Obtener_Valor(Tama�oMensaje, Mensaje);

    delete[] Mensaje;
    Mensaje = nullptr;

    system("pause>0");
    return 0;
}