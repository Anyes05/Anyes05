#include <iostream>
using namespace std;

int main() {
    bool dentro_de_palabra = false;
    char c;
    int palabras = 0;
    while ((c = getchar()) != EOF) {
        if ( (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')){
            if (!dentro_de_palabra) {
                palabras++;
                dentro_de_palabra = true;
            }
        }
        else {
            if (dentro_de_palabra) {
                dentro_de_palabra = false;
            }
        }
    }
    cout << "La cantidad de palabras leídas es: " << palabras << endl;
    return 0;
}