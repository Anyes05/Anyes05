#include <iostream>
using namespace std;

int main()
{
    char c;
    int num;
    int arr[10] = {0};

    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            num = c - '0';
            arr[num]++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "cantidad de ocurrencias del numero " << i << "-->" << arr[i] << endl;
    }

    return 0;
}
