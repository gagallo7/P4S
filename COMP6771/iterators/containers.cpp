#include <iostream>
#include <deque>
#include <list>

using namespace std;

int main ()
{
    deque < double > dq1 ;
    deque < int > dq2 ;
    list < int > lst;

    //dq1 = dq2; // NO
    //dq1 = lst; // NOT
    //lst = dq2; // NO
    dq1.assign(dq2.begin(), dq2.end());
    dq1.assign(lst.begin(), lst.end());
    lst.assign(dq2.begin(), dq2.end());
    /*
    */

    return 0;
}
