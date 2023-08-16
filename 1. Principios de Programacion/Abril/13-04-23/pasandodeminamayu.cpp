#include <iostream> 
using namespace std;

int main()
{
    char c;

    cout << "Introducir caracter ASCII \n";

    while ((c=getchar())!=EOF) //con esto podemos decir que ingrese un tipo de dato char
    {
        if ((c>='a')&&(c<='z')) //comprobamos si es  miniscula
        {
           c=c-('a'-'A');
           putchar(c);
        }else if((c>='A')&&(c<='Z')){ //comprobamos si es mayuscula
            c=c-('A'-'a');
           putchar(c);
        }
        
    }

    return 0;
    
}
