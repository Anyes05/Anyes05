#include <iostream>
using namespace std;

// version optimizada en moodle

int main()
{
    int MAX = 10;
    int num[] = {2, 65, 8, 9, 90, 81, 635, 5, 7, 10};
    int maximo = num[0];
    int minimo = num[0];
    int cont = 1;
    int contmin = 1;

    for (int i = 1; i < MAX; i++)
    {
        if (num[i] == maximo)
        {
            cont++;
        }else if (num[i] == minimo){
            contmin ++;
        }

        if (num[i] > maximo)
        {
            maximo = num[i];
            cont = 1;
        }else if (num[i] < minimo)
        {
            minimo = num[i];
            cont = 1;
        }
        
    }

    cout << "el maximo es: " << maximo << "su cantidad de ocurrencias es: " << cont << " y el minimo es: " << minimo << "su cantidad de ocurrencias es: " << contmin << endl;

    return 0;
}
