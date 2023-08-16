#include <iostream>
using namespace std;

int main()
{

    // maximo comun divior entre dos numeros

     int num1, num2, divisor = 1, maxdiv;

    cout << "Ingrese el pirmer num" << endl;
    cin >> num1;
    cout << "Ingrese el segundo num" << endl;
    cin >> num2;

    while (divisor <= num1 && divisor <= num2)
    {
        if (num1 % divisor == 0 && num2 % divisor == 0)
        {
            maxdiv = divisor;
        }

        divisor ++;
    }
    
    cout << "El maximo comun divisor: " << maxdiv;

    return 0;
}
