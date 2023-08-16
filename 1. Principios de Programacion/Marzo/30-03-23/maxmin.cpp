#include <iostream>
using namespace std;

int main()
{

    // que el usuario ingrese la cantiadad de numeros que va a leer, y mostrar cuales de los sieguientes es max y min


    int num = 0, max = 0, min = 0, cont = 0, i = 0;
    do
    {
        cout << "Cuantas veces quieres poner un numero: " << endl;
        cin >> cont;

        if (cont < 1)
        {
            cout << "La cantidad deber ser al menos 1. Chau" << endl;
        }

    } while (cont < 1);

    // en vez de comenzar con la condicion, primero realiza la accion y despues consulta.
    do
    {
        cout << "Ingrese otro num numero: " << endl;
        cin >> num;

        if (i == 1)
        {
            min = max = num;
        }
        else
        {
            if (num > max)
            {
                max = num;
            }
            else if (num < min)
            {
                min = num;
            }
        }

        i++;

    } while (i < cont);

    cout << "El maximo es: " << max << " y el minimo es: " << min;

    return 0;
}