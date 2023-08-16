#include <iostream>
using namespace std;

int main()
{
    char c;

    cout << "Introducir constraseña fea  \n";

    while ((c = getchar()) != EOF)
    {

        if ((c >= 'a') && (c <= 'z') || (c >= 'A') && (c <= 'Z'))
        {
            if (c == 'A')
            {
                c = '4';
                putchar(c);
            }
            else if (c == 'a')
            {
                c = '@';
                putchar(c);
            }
            else if ((c == 'i') || (c == 'I'))
            {
                c = '1';
                putchar(c);
            }
            else if ((c == 'e') || (c == 'E'))
            {
                c = '3';
                putchar(c);
            }
            else if ((c == 'o') || (c == 'O'))
            {
                c = '0';
                putchar(c);
            }
            else if ((c == 'u') || (c == 'U'))
            {
                c = ')';
                putchar(c);
            }
            putchar(c);
        }

    }

    return 0;
}