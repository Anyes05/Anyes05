#include <iostream>
using namespace std;

int main()
{

    int n, i = 0;
    cout << "Ingrese un num natrual";
    cin >> n;
    do
    {
        if (i * i == n)
        {
            cout << "Es cudrado";
            return 0;
        }
        i++;
    } while (i * i <= n);
    cout << "no es cuadrado";

    return 0;
}
