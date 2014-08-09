#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    vector<int> v1(10, 1);
    vector<int> v2(5, 2);
    auto first = v1.cbegin();
    v2.swap(v1);
    auto last = v2.cend();
    while (first != last) {
        cout << *first << endl;
        ++first;
    }

    return 0;
}
