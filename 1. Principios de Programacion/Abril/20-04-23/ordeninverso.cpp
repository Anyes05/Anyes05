#include <iostream>
using namespace std;
#define MAX 10

// int y char son lo mismo
int main()
{
    int x[MAX];
    cout << "Ingrese un numero: " << endl;

    for (int i = 0; i < MAX; i++)
    {
        cout << "Ingrese otro numero" << endl;
        cin >> x[i];
    }

    for (int j = MAX - 1; j >= 0; j--)
        cout << x[j] << endl;

    return 0;
}
