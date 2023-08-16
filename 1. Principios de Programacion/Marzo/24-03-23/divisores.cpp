#include <iostream>
using namespace std;

int main()
{
    // dado un numero diga todo los divisores

    int num, i = 1;

    cout << "Introduce un numero: " << endl;
    cin >> num;

    while (i <= num)
    {
        if (num % i == 0)
        {
            cout << "Sus divisores son: " << i << endl;
        }
        i++;
    }
    return 0;
}
