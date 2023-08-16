#include <iostream>
#include <math.h>
using namespace std;

// ***************** DEFINICIÓN DE ESTRUCTURAS **************
struct punto {
    int x;
    int y;
};

struct segmento {
    punto p1;
    punto p2;
};

struct rectangulo {
    unsigned largo;
    unsigned ancho;
};

// ***************** DEFINICIÓN DE FUNCIONES **************

int valor_absoluto (int);
float distancia(segmento);
void test_distancia ();
float area (rectangulo);
rectangulo getRectanguloMayor (rectangulo[], int);

// ****************** MAIN ********************************

int main() {
    rectangulo propio;
    propio.largo = 20;
    propio.ancho = 10;
    std::cout << "Area del rectangulo: " << area(propio);
    return 0;
}


// ***************** IMPLEMENTACIÓN DE FUNCIONES **********

void test_distancia () {
    segmento segmentito;
    segmentito.p1.x = 3;
    segmentito.p1.y = 3;
    segmentito.p2.x = 3;
    segmentito.p2.y = 3;
    std::cout << "La distancia del segmento es: " << distancia(segmentito);
}

int valor_absoluto (int x) {
    if (x < 0)
        x *= -1;
    return x;
}

float distancia(segmento s) {
    int cat1 = valor_absoluto (s.p1.x - s.p2.x);
    int cat2 = valor_absoluto (s.p1.y - s.p2.y);
    float hipotenusa = sqrt(pow(cat1,2) + pow(cat2,2));
    return hipotenusa;
}

float area (rectangulo r) {
    return r.ancho * r.largo;
}

rectangulo getRectanguloMayor (rectangulo arr [], int largo) {

}