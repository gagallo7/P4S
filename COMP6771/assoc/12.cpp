#include<iostream>
#include<deque>
#include<vector>
#include<fstream>
#include<iterator>

using namespace std;

int main ()
{
    vector<int> ivec;
    for (int i = 0; i < 20; ++i)
        ivec.push_back(i);
    deque<int> ideq;
    deque<int> ideq2( ivec.rbegin(), ivec.rend() );

    ideq.assign ( ivec.rbegin(), ivec.rend() );

    for ( auto i = begin(ideq); i != end(ideq); i++ )
    {
        cout << *i << " ";
    }
    cout << endl;

    ofstream os ("mynums.txt", ofstream::out);

    auto A = begin(ideq);
    auto B = end(ideq);
    copy ( A, B, ostream_iterator <int> ( os, "\n" ) );
    
    os.close();
}
