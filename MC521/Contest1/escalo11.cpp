#include <iostream>
#include <utility> 
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>

#define MAX(x,y) (x) > (y) ? (x) : (y)

using namespace std;

enum colors
{
    WHITE, GRAY, BLACK
};

bool DFSCycleDetect ( vector < list < int > >& adjL )
{
    stack < int > next;
    int time = 0;
    int x;

    vector < int > s ( adjL.size() );
    vector < int > color ( adjL.size(), WHITE );
    vector < int > e ( adjL.size() );

    list < int >::iterator li;

    for ( int i = 0; i < adjL.size(); i++ )
    {
        if ( color [i] == BLACK )
        {
            continue;
        }

        color [i] = GRAY;
        s [i] = time++;
        e [i] = INT_MAX;

        for ( li = adjL[i].begin(); li != adjL[i].end(); li++ )
        {
            // BACKWARD EDGE
            if ( e [ *li ] > time )
            {
                return true;
            }
            next.push ( *li );
        }

        while ( next.size() )
        {
            x = next.top (); 
            next.pop(); 

            color [x] = GRAY;
            s [x] = time++;
            e [x] = INT_MAX;

            for ( li = adjL[x].begin(); li != adjL[x].end(); li++ )
            {
                // BACKWARD EDGE
                if ( e [ *li ] > time )
                {
                    return true;
                }
                next.push ( *li );
            }
            color [x] = BLACK;
            e [x] = time++;
        }

        color [i] = BLACK;
        e [i] = time++;

    }

    return false;
}


bool BFSCycleDetect ( vector < list < int > >& adjL )
{
    queue < int > q;

    vector < int > v ( adjL.size(), WHITE );

    int x;
    list < int >::iterator li;

    for ( int i = 0; i < adjL.size(); i++ )
    {
        if ( v[i] == BLACK )
        {
            continue;
        }

        cout << i << " is not black" << endl;

        for ( li = adjL[i].begin(); li != adjL[i].end(); li++ )
        {
            if ( v [*li] != WHITE )
            {
                cout << "!!! " << *li << " is not white!" << endl;
                return true;
            }

            cout << *li << " is being added to the queue and filled in gray" << endl;
            v [*li] =  GRAY;
            q.push ( *li );
        }

        cout << "Sweepping the queue..." << endl;
        while ( !q.empty() )
        {
            x = q.front ();
            q.pop();

            for ( li = adjL[x].begin(); li != adjL[x].end(); li++ )
            {
                if ( v [*li] != WHITE )
                {
                    cout << "!!! " << *li << " is not white!" << endl;
                    return true;
                }
                v [*li] =  GRAY;
                cout << *li << " is being added to the queue and filled in gray" << endl;
                q.push ( *li );
            }
        }
        cout << "Sweept." << endl;

        v [i] =  BLACK;
    }
    return false;
}

bool pairCmp ( pair < int, int > a, pair < int, int > b )
{
    if ( a.second == b.second )
    {
        if ( b.second == a.first )
        {
            return 1;
        }
        return ( a.first < b.first );
    }
    return ( a.second < b.second );
}



int main ()
{
    int n, m, a, b;
    cin >> n >> m;

    vector < list < int > > adjL (n);
    vector < pair < int, int > > componentVal ( adjL.size() );

    for ( int i = 0; i < adjL.size(); i++ )
    {
        componentVal [i].first = i;
    }

    for ( int i = 0; i < m; i++ )
    {   
        cin >> a >> b;

        adjL [ b ].push_back ( a );
        if ( componentVal [b].second < a ) 
        {
            componentVal [b].second = a;
        }
    }   

    for ( int i = 0; i < adjL.size(); i++ )
    {
        cout << "c" << i << " "<< componentVal[i].first << " " << componentVal[i].second << endl;
    }

    sort ( componentVal.begin(), componentVal.end(), pairCmp );

    for ( int i = 0; i < adjL.size(); i++ )
    {
        cout << "c" << i << " "<< componentVal[i].first << " " << componentVal[i].second << endl;
    }

    if ( DFSCycleDetect ( adjL ) )
    {
        cout << "*" << endl;
        return 0;
    }

    list <int>::iterator li;
    vector < bool > check ( adjL.size(), false );

    for ( int i = 0; i < adjL.size(); i++ )
    {
        if ( check[i] )
        {
            continue;
        }
        check[i] = true;

        for ( li = adjL[i].begin(); li != adjL[i].end(); li++ )
        {
            if ( check[*li] )
            {
                continue;
            }
            check[*li] = true;
            
            cout << *li << endl;

        }

        cout << i << endl;
    }

    for ( int i = 0; i < adjL.size(); i++ )
    {
        cout << componentVal [i].first << endl;
    }

    return 0;
}
