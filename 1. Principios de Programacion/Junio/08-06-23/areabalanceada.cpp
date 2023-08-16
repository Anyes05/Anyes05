#include <iostream>
using namespace std;

struct rectangulo
{
    unsigned largo;
    unsigned ancho;
};

float area(rectangulo r)
{
    return r.ancho * r.largo;
}

float area(rectangulo);

bool areaBalanceada(rectangulo arr[], int index, int n)
{
    int suma1;
    int suma2;

    for (int i = index +1, j=index-1; ((i<n) || (j>=0)); i++, j--)
    {
        if (j>=0)
        {
            suma1 += area(arr[j]);
        }
        if (i<n)
        {
           suma2 +=area(arr[i]);
        } 
        
    }

    return suma1 == suma2;
}

int main(){

    rectangulo propio;
    propio.largo = 20;
    propio.ancho = 10;
    int index = 5;
    return 0;
}
