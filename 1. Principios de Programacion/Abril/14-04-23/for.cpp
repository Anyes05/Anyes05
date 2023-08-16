#include <iostream>
using namespace std;

int main() {
  // for (int i = 0; i <= 10; i += 2) {
  //   cout << i << endl;
  // }

  // Si es divisor de 3 y 5 fizzbuzz
  // si es divisor de 3 fizz, y de 5 buzz

  // for(int i = 0; i <= 20; i++) {
  //   if(i == 6) {
  //     i+=4;
  //     // Tambien se puede poner i = 10;

  //   }

  //   cout << i << endl;

  // }

  // for(int i = 0; i<= 20; i++) {

  //   switch(i) {
  //     case 6:
  //       break;
  //     case 7:
  //       break;
  //     case 8:
  //       break;
  //     case 9:
  //       break;

  //     default:
  //       cout << i << endl;
  //       break;
  //   }

  // }

  // Sumar el numero de arreglos;
  //   int a[9] = {2,4,5,6,7,8,9,7,7};
  //   int suma = 0;
  //   for(int i = 0; i <= 8; i++ ) {
  //     suma += a[i];

  //   }

  //   cout << suma << endl;

  //   int arr[10] = {1,1,1,1,1,1,1,1,1,1};
  //   int suma2 = 0;

  //   for(int i = 0; i<= 9; i++) {
  //     suma2 += arr[i];

  //   }

  //   cout << suma2 << endl;
  // }

  // char papaya[12] = {'p', 'a', 'p', 't', 'p', 'a', 'p', 'a', 'y', 'a'};
  //   bool ok = false;

  // for(int i = 0; (i <= 11-6) && !ok; i++) {
  //   if(papaya[i] == 'p') {
  //     if(papaya[i+1] == 'a') {
  //       if(papaya[i+2] == 'p') {
  //         if(papaya[i+3] == 'a') {
  //           if(papaya[i+4] == 'y') {
  //             if(papaya[i+5] == 'a') {
  //             }
  //             ok = true;
  //           }

  //         }

  //       }

  //     }

  //   }
  // }

  //   if(ok) {

  //     cout << "Se encontro la palabra" << endl;
  // //   }
  // char papaya[200];
  // char buscar[6] = {'p', 'a', 'p', 'a', 'y', 'a'};
  // bool ok = false;

  // int c;
  // int i = 0;

  // while((c=getchar()) != EOF) {
  //   papaya[i] = c;
  //   i++;
  // }

  // for (int i = 0; i <= 200 - 6; i++) {

  //   for (int j = 0; j < 6; j++) {
  //     if (papaya[i + j] != buscar[j]) {
  //       break;
  //     }

  //     if (j == 5) {
  //       ok = true;
  //     }
  //   }
  // }

  // if (ok) {
  //   cout << "Se ha encontrado la palabra" << endl;
  // } else {
  //   cout << "no está" << endl;
  // }

  // Ahora para hacerlo más inteligente

  char palabra_buscar[200];
  char texto[200];
  int cantBuscar = 0;
  int cantTexto = 0;
  int c;
  bool ok = false;

  while ((c = getchar()) != '\n') {

    palabra_buscar[cantBuscar++] = c;
  }

  while ((c = getchar()) != '\n') {

    texto[cantTexto++] = c;
  }

  for (int i = 0; (i <= cantTexto - cantBuscar) && !ok; i++) {
    for (int j = 0; j < 6; j++) {
      if (texto[i + j] != palabra_buscar[j]) {
        break;
      }

      if (j == cantBuscar - 1) {
        ok = true;
      }
    }
  }

  if (ok) {
    cout << "La palabra se ha encontrado correctamente" << endl;

  } else {
    cout << "La palabra no se ha encontrado" << endl;
  }
}
