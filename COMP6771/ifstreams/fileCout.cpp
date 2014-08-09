#include <iostream>
#include <fstream>

int main ()
{
    int i = 200, i2;
    double d = 3.14159, d2;

    std::ofstream os ("myfile.txt", std::ofstream::out);

    os << i << d;
    os.close();

    std::ifstream is ("myfile.txt");
    is >> i2 >> d2;
    is.close();

    std::cout << "Read: " << i2 << " " << d2 << "\n";

    return 0;
}
