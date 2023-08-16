#include <iostream>
using namespace std;

int main()
{
    /*Es primo o no*/

    int num, i = 2, div = 0;

    cout << "Introduce un numero: " << endl;
    cin >> num;

    while (num % i != 0 && div <= 2)
    {
        i++;
        div++;
    }

    if (i == num)
    {
        cout << "Primo" << endl;
    }
    else
    {
        cout << "No es primo" << endl;
    }

    return 0;
}
