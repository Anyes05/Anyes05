#include <iostream>
using namespace std;

//invierte las palabras

int main()
{
    char c;
    char arreglo [10];
    int i = 0;

    while ((c=getchar()) != EOF)
    {
        
        arreglo [i] = c;
        i++;
    }
    // mostrar info del arreglo

    while (i > 0)
    {
        putchar(arreglo[i-10]);
        i--;
    }
    


    return 0;
}