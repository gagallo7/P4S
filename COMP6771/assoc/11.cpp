#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main ()
{
    vector<int> ivec(1, 1);
    map< vector<int>, vector<int>> ivmap;
    ivmap[ivec].push_back(2);
    (*ivmap[ivec].begin())++;
    cout << ivmap[ivec][0] << endl;

}
