#include <iostream>
using namespace std;
#include <limits>
#include <cstdlib>std::

struct persona
{
    string nombre;
    string apellido;
    string cedula;
};

// FUNCIONES
void menu();
void esperar();
bool estaPersona(string, persona[], int);
int darPosicion(string, persona[], int);

int main()
{
    int opcion, posicion;
    string ci, nom, apell;

    persona misPersonas[100], arr[100];
    int cantPersonas = 0;

    do
    {
        menu();
        cin >> opcion;
        getchar();
        system("CLS");
        switch (opcion)
        {
        case 1:
            std::cout << "Ingrese cedula: ";
            // Lee una línea de caracteres hasta encontrar un ENTER
            getline(cin, ci);
            if (estaPersona(ci, misPersonas, cantPersonas))
            {
                system("CLS");
                std::cout << "Ya existe una persona con esa cédula." << endl;
                esperar();
            }
            else
            {
                misPersonas[cantPersonas].cedula = ci;
                system("CLS");
                std::cout << "Ingrese nombre: ";
                getline(cin, nom);
                misPersonas[cantPersonas].nombre = nom;
                system("CLS");
                std::cout << "Ingrese apellido: ";
                getline(cin, apell);
                misPersonas[cantPersonas].apellido = apell;
                system("clear");
                cantPersonas++;
            }
            break;
        case 2:
            system("CLS");
            if (cantPersonas == 0)
            {
                std::cout << "No existen personas en el sistema." << endl;
                esperar();
                break;
            }
            std::cout << "LISTADO DE PERSONAS" << endl;

            
            for (int i = 0; i < cantPersonas; i++)
            {
              
                std::cout << "---- Persona " << i + 1 << " ----" << endl;
                std::cout << "Cedula: " << misPersonas[i].cedula << endl;
                std::cout << "Nombre: " << misPersonas[i].nombre << endl;
                std::cout << "Apellido: " << misPersonas[i].apellido << endl
                          << endl;
            }
            esperar();
            break;
        case 3:
            std::cout << "Ingrese cedula: ";
            getline(cin, ci);
            posicion = darPosicion(ci, misPersonas, cantPersonas);
            if (posicion == -1)
            {
                system("CLS");
                std::cout << "No existe una persona con esa cédula." << endl;
                esperar();
            }
            else
            {
                system("CLS");
                std::cout << "Ingrese nuevo nombre: ";
                getline(cin, nom);
                misPersonas[posicion].nombre = nom;
                system("CLS");
                std::cout << "Ingrese nuevo apellido: ";
                getline(cin, apell);
                misPersonas[posicion].apellido = apell;
                system("CLS");
            }
            break;
        case 4:
            std::cout << "Ingrese Cedula: ";
            getline(cin, ci);
            posicion = darPosicion(ci, misPersonas, cantPersonas);
            if (posicion == -1)
            {
                system("CLS");
                std::cout << "No existe una persona con esa cédula." << endl;
                esperar();
            }
            else
            {
                for (int j = posicion; j < cantPersonas - 1; j++)
                {
                    misPersonas[j] = misPersonas[j + 1];
                }
                cantPersonas--;

                //    system("clear");
                //    misPersonas[posicion] = misPersonas[cantPersonas -1];
                //    cantPersonas --;
            }
            break;
        case 5:
            int min, cant= 0;
            persona tmp;
            for (int r = 0; r < cant -1; r++)
            {
                min = r;
                for (int t = r+1; t < cant; t++)
                {
                   if ( arr[t].cedula < arr[min].cedula)
                   {
                    min = t;
                   }
                   if (min!=r)
                   {
                    tmp = arr[r];
                    arr[r]= arr[min];
                    arr[min]=tmp;
                   }
                   
                }
                
            }
            
        }

    } while (opcion != 0);

    return 0;
}

void esperar()
{
    std::cout << endl
              << "[ PRESIONE ENTER PARA CONTINUAR ]";
    // PAUSA EL SISTEMA HASTA QUE SE INGRESE ENTER
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("CLS");
}

void menu()
{
    std::cout << "## Bienvenidos al Sistema ##" << endl;
    std::cout << "Ingrese una de las siguientes opciones:" << endl;
    std::cout << "   1. Ingresar Persona" << endl;
    std::cout << "   2. Listar Personas" << endl;
    std::cout << "   3. Modificar Persona" << endl;
    std::cout << "   4. Eliminar Persona" << endl;
    std::cout << "   5. Listar Personas de Forma Ordenadas" << endl;
    std::cout << "   0. Salir" << endl;
}

bool estaPersona(string ci, persona arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].cedula == ci)
            return true;
    }
    return false;
}

int darPosicion(string ci, persona arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].cedula == ci)
            return i;
    }
    return -1;
}
