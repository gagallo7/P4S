#include <iostream>

#define P(x) (1 << x);

using namespace std;

int marked = 0;
int big= 12;

int choose ( int num, int add, int sub )
{
    int pos, pos2;
    int aux = num - sub + add;

    if ( num >= 0 )
    {
        pos = 1 << num;
        pos2 = 1 << aux;
        if ( (marked&pos) == 0 )
            if ( (marked&pos2) == 0 )
        {
            marked |= pos;
        }
        else
        {
            while ( (marked&pos) || (marked&pos2) )
            {
                num++;
                pos <<= 1;
                pos2 <<= 1;
            }
            big = num;
            marked |= pos;
        }
    }
    return num;
}

int choose2 ( int num )
{
    int pos;
    if ( num >= 0 )
    {
        pos = 1 << num;
        if ( (marked&pos) == 0 )
        {
            marked |= pos;
        }
        else
        {
            while ( (marked&pos) )
            {
                num++;
                pos <<= 1;
            }
            big = num;
            marked |= pos;
        }
    }
    return num;
}

    int v [1000][1000];

void makeNumCol ( int i, int j )
{
    if ( !v[i][j+1] )
    {
        //v[i][j+1] = choose ( big+1, v[i+1][j] + v[i][j+1], v[i][j] );
        v[i][j+1] = choose2 ( big+1 );
    }
    v[i+1][j+1] = v[i+1][j] + v[i][j+1] - v[i][j]; 
    while ( (marked& (1 << v[i+1][j+1])) )
    {
        marked -= v[i][j+1];
        makeNumCol ( i, j);
    }
    marked |= P(v[i+1][j+1]);
    cout << "Col v" << i+1 << "," << j+1 << " = " << v[i+1][j+1] << " =  " << v[i+1][j] << " + " << v[i][j+1] << " - " << v[i][j] << endl; 
}

void makeNumRow ( int i, int j )
{
    if ( !v[i+1][j] )
    {
//        v[i+1][j] = choose ( big+1, v[i+1][j] + v[i][j+1], v[i][j] );
        v[i+1][j] = choose2 ( big+1 );
    }
    v[i+1][j+1] = v[i+1][j] + v[i][j+1] - v[i][j]; 
    while ( (marked& (1 << v[i+1][j+1])) )
    {
        marked -= v[i+1][j];
        makeNumRow ( i, j);
    }
    marked |= P(v[i+1][j+1]);
    cout << "Row v" << i+1 << "," << j+1 << " = " << v[i+1][j+1] << " =  " << v[i+1][j] << " + " << v[i][j+1] << " - " << v[i][j] << endl; 
}

int main ()
{
    int n, S;
    
    v [0][0] = 1;
    v [0][1] = 2;
    v [0][2] = 5;
    v [1][0] = 3;
    v [1][1] = 4;
    marked += 62;
    v [1][2] = 7;
    marked += 1 << 7;
    marked |= P(8);
    marked |= P(9);
    marked |= P(12);

    v [2][0] = 8;
    v [2][1] = 9;
    v [2][2] = 12;

    cout << endl << (marked& (1 << 9) ) << endl;
    cin >> n >> S;

    for ( int i = 2; i < n-1; i++ )
    {
        for ( int j = 0; j <= i; j++ )
        {
            makeNumRow ( i, j );
            makeNumCol ( j, i );
        }
    }

    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            cout << v [i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
