#include <iostream>
using namespace std;

int main()
{

    int num1, num2, i = 1, mcm, max;

    cout << "Ingrese el pirmer num" << endl;
    cin >> num1;
    cout << "Ingrese el segundo num" << endl;
    cin >> num2;

    if (num1 > num2)
    {
        max = num1;
    }
    else
    {
        max = num2;
    }

    while (max % num1 != 0 || max % num2 != 0)
    {
        max++;
    }
    cout << "El minimo comun multiplo: " << max;

    return 0;
}
