#include <iostream>
using namespace std;

int main()
{
    int calificacion;
    float total = 0;
    float promedio;
    int cont = 1;

    while (cont <= 3)
    {
        cout << "Ingrese la proxima calificacion: " << endl;
        cin >> calificacion;
        total = total + calificacion;
        cont = cont + 1;
    }
    promedio = total / 3;
    cout << "El promedio de calificaciones es: " << promedio << endl;
    return 0;
}
