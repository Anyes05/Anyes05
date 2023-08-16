#include <iostream>
using namespace std;

int main()
{
    char tablero[9][9];
    
    bool ok = false;
    for (int i = 0; i < 9 && !ok; i++)
    {
        for (int j = 0; j < 5 && !ok; j++)
        {
            if (tablero[i][j] == 'm' && tablero[i][j + 1] == 'a' && tablero[i][j + 2] == 'n' && tablero[i][j + 3] == 'g' && tablero[i][j + 4] == 'o')
            {
                ok = true;
            }
        }
    }

    if (ok)
        cout << "Mango esta";
    else
        cout << "Mango no esta";

    return 0;
}
