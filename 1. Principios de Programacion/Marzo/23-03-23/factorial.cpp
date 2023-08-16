#include <iostream> 
using namespace std;

int main(int argc, char const *argv[])
{
    long num;
    long i = 1;
    long fac = 1;

    cout << "Ingrese un numero: " << endl;
    cin >> num;

    while (i <= num)
    {
        fac = fac * i;
        i = i + 1;
    }

    cout << fac << endl;
    return 0;
}
