#include <iostream>

void swap3(int &x, int &y, int &z)
{
    int tmp;
    if ( x <= y )
    {
        std::cout << "Case 1\n";
        if ( y > z ) // x < y , y > z
        {
            tmp = y;
            y = z;
            z = tmp;

            if ( y < x )
            {
                std::cout << "Case 1a\n";
                tmp = x;
                x = y;
                y = tmp; // x < y < z
            }

        }
    }
    else if ( y <= z )
    {
        std::cout << "Case 2\n";
        if ( z < x ) // y < z < x
        {
            std::cout << "Case 2a\n";
            tmp = x;
            x = z;
            z = tmp; // y < x < z
            tmp = y;
            y = x;
            x = tmp;
        }
    }
    else // x > y > z
    {
        std::cout << "Case 3\n";
        tmp = x;
        x = z;
        z = tmp; // z > y > x
    }
}

int main ()
{
    int a = 1, b = 2, c = 3;

    swap3 ( c, b, a );
    std::cout << a << b << c; // 3 2 1
    std::cout << "\n";

    swap3 ( c, a, b ); //  1 3 2
    std::cout << a << b << c; // 2 3 1
    std::cout << "\n";

    swap3 ( a, b, c );
    std::cout << a << b << c; // 1 2 3
    std::cout << "\n";

    return 0;
}
