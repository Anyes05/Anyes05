#include <iostream>
using namespace std;

int main()
{

    char c;
    bool ok = false;

    cout << "Introducir una frase \n";

     while ((c = getchar()) != EOF)
    {
        if (c == 'h')
        {
            if ((c = getchar()) == 'o')
            {
                if ((c = getchar()) == 'y')
                {
                    ok = true;
                }
                
            }
            
        }
        
    }

    if (ok)
    {
       cout << "La palabra --hoy-- fue econtrada";
    }else{
        cout << "La palabra --hoy-- no fue econtrada";
    }
    

    return 0;
}