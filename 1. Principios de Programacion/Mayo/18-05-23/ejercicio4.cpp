#include <iostream>
using namespace std;

int main()
{
    
    int num, i , j;
    float promedio;
    int ocurrencias [5] = {0};
    
    for ( i = 0; i < 10; i++)
    {
        cin >> num;
        ocurrencias[num -1]++;
        promedio += num;
    }
    
    system("clear");
    for ( i = 4; i >= 0; i--)
    {
        cout << i+1 << " .. ";
        for ( j = 0; j < ocurrencias[i]; i++)
        {
            cout << ".";
        }
        if (j == 0)
        {
            cout << "nada por aqui";
        }
         cout << "PRomedio de calficaciones: " << promedio / 10 << endl;
        
    }
    


    return 0;
}
