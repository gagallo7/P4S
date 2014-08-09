#include <iostream>
#include <cmath>

int main ()
{
    double s, a, b, c;

    std::cout << "Type the sides-lenghts of a triangle to obtain this area.\n";

    std::cin >> a >> b >> c;

    s = (a+b+c)/(double)2;

    std::cout << "semi perimeter = " << s << " area: " << sqrt ( s * (s-a) * (s-b) * (s-c) ) << std::endl;

    return 0;
}
