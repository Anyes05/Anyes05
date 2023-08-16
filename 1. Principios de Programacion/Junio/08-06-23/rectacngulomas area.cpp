#include <iostream>
#include <math.h>
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
        if (area (arr[i])>area(arr[arr[i++]]))
        {
            return false;
        }
        
    }
    return true;
}

rectangulo rectanguloMayorArea(rectangulo arr[], int n){

    int max_area, area_temp;
    rectangulo mayor = arr[0];
    max_area =  area(mayor);
    for (int i = 1; i < n; i++)
    {
        area_temp>area(arr[i]);
    }
    

}

int main()
{
    
    return 0;
}
