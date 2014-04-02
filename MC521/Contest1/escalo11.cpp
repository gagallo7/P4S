#include <iostream>
#include <utility> 
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
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
/*
L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edges
while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
if graph has edges then
    return error (graph has at least one cycle)
else 
    return L (a topologically sorted order)
*/

list < int > topoSort ( vector < list < int > > g )
{
    list < int > L;
    vector < int > S (g.size(), 0);
    queue < int > Sl;

    list < int >::iterator li;

    for ( int i = 0; i < g.size(); i++ )
    {
        for ( li = g[i].begin(); li != g[i].end(); li++ )
        {
            S [*li]++;
        }
    }

    //for ( int i = g.size()-1; i >= 0; i-- )
    for ( int i = 0; i < g.size(); i++ )
    {
        if ( S[i] == 0 )
        {
            Sl.push (i);
        }
    }


    while ( Sl.size() )
    {
        int i = Sl.front();
        L.push_back (i);
        Sl.pop();
        for ( li = g[i].begin(); li != g[i].end(); li++ )
        {
            if ( --S[*li] == 0 )
            {
                Sl.push (*li);
            }
        }
    }

    for ( int i = 0; i < g.size(); i++ )
    {
        if ( S[i] > 0 )
        {
            list < int > error (1, -1);
            return error;
        }
    }

    return L;
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
        return ( a.first > b.first );
    }
    /*
    */
    return ( a.second < b.second );
}

bool pairCmp2 ( pair < int, int > a, pair < int, int > b )
{
    /*
    if ( a.second == b.second )
    {
        if ( b.second == a.first )
        {
            return 1;
        }
        return ( a.first < b.first );
    }
    */
    return ( a.second < b.second );
}


int main ()
{
    int n, m, a, b;
    cin >> n >> m;

    vector < list < int > > adjL (n), aux (n);
    vector < pair < int, int > > w (n, pair < int, int > (0, 0) );

    list <int>::iterator li;

    for ( int i = 0; i < m; i++ )
    {   
        cin >> a >> b;

        adjL [ b ].push_back ( a );
        aux [a].push_back (b);
    }   

    list < int > L = topoSort ( adjL );

    if ( L.size() == 1 )
    {
        if ( L.front() == -1 )
        {
            cout << "*" << endl;
            return 0;
        }
    }

    for ( int i = adjL.size()-1; i >= 0; i-- )
    {
        w[i].first = i;
        w[i].second = i;
    }

    for ( int i = adjL.size()-1; i >= 0; i-- )
    {
        for ( li = aux[i].begin(); li != aux[i].end(); li++ )
        {        
            w [*li].second += w[i].second;
        }
    }

    /*
    cout << endl;
    for ( int i = 0; i < adjL.size(); i++ )
    {
        cout << w[i].first << " " << w[i].second << endl;
    }
*/
    sort ( w.begin(), w.end(), pairCmp );
    for ( int i = 0; i < adjL.size(); i++ )
    {
        cout << w[i].first << endl;
    }
    //make_heap ( w.begin(), w.end(), pairCmp );
/*
    for ( int i = 0; i < adjL.size(); i++ )
    {
        cout << w[i].first << " " << w[i].second << endl;
    }


  
    int max = adjL.size()-1;
    while ( w.size () )
    {
        int n = w.front().first;
        cout << n << endl;
        pop_heap ( w.begin(), w.end(), pairCmp );
        w.pop_back();

        for ( li = aux[n].begin(); li != aux[n].end(); li++ )
        {
            int j = 0;
            while ( *li != w[j].first )
            {
                j++;
            }
            w [j].second -= n;
            cout << "w" << j << " -= " << n << endl;
        }

        sort_heap ( w.begin(), w.end() );
    //sort ( w.begin(), w.end(), pairCmp );
        cout << endl;
        for ( int i = 0; i < max; i++ )
        {
            cout << w[i].first << " " << w[i].second << endl;
        }
        max--;
    }

*/



    /*
    for ( int i = 0; i < adjL.size(); i++ )
    {
        //cout << "c" << i << " "<< componentVal[i].first << " " << componentVal[i].second << endl;
    }

    sort ( componentVal.begin(), componentVal.end(), pairCmp );

    for ( int i = 0; i < adjL.size(); i++ )
    {
      //  cout << "c" << i << " "<< componentVal[i].first << " " << componentVal[i].second << endl;
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
    */



    /*
    list < int >::reverse_iterator rli;

    for ( rli = L.rbegin(); rli != L.rend(); rli++ )
    {
        cout << *rli << endl;
    }
    */

    return 0;
}
