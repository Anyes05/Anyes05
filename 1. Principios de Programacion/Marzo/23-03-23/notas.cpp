#include <iostream> 
using namespace std;


int main()
{
   
    float calificacion;
    int cont = 0;
    int centinela;
    int aprobados = 0;
    int reprobados = 0;

    cout << "Ingrese -1 si no hay mas notas para ingresar, u otra cosa en caso contrario " << endl;
    cin >> centinela;

    while (centinela != -1)
    {
        cout << "Ingrese la calificacion: " << endl;
        cin >> calificacion;
        if (calificacion <= 60)
        {
            aprobados = aprobados + 1;
        }
        else
        {
            reprobados = reprobados + 1;
        }
        cont = cont + 1;
        cout << "Ingrese -1 si no hay mas notas para ingresar, u otra cosa en caso contrario " << endl;
        cin >> centinela;
    }
    cout << "La cantidad de reprobados son: " << reprobados << endl;
    cout << "La cantidad de aprobados son: " << aprobados << endl;

}
