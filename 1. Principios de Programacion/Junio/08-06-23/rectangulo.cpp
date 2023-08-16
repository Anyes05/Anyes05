#include <iostream>
using namespace std;

struct rectangulo
{
    unsigned largo;
    unsigned ancho;
};

float area (rectangulo r) {
    return r.ancho * r.largo;
}
float area (rectangulo);

rectangulo getRectanguloMayor (rectangulo[], int);

bool estaOrdenadoArea(rectangulo arr[], int n){
    for (int i = 0; i<n-1;i++){
        if (area (arr[i])>area(arr[i++]))
        {
            return false;
        }
        
    }
    return true;
}

int main()
{
    rectangulo propio;
    propio.largo = 20;
    propio.ancho = 10;
    cout << "Area del rectangulo: " << area(propio);
    return 0;
}
