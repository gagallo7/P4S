#include <cstdio>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

int mlevel = 0;

void printList ( list < pair < int, int > > tree )
{
    list < pair < int, int > >::iterator i;
    for ( i = tree.begin(); i != tree.end(); i++ )
    {
        printf ( "%d/%d ", (*i).first, (*i).second );
    }
    printf ( "\n" );
}

float addTreeRight ( vector < pair < int, int > >& tree, int pos, int b )
{
    int m, n, mm, nn;
    /*
       if ( tree [pos+1].second == 0 )
       {
       */
    m = tree [pos].first;
    n = tree [pos].second;
    mm = tree [pos+1].first;
    nn = tree [pos+1].second;

    //vi--;

    pair < int, int > novo ( m+mm, n+nn );

    tree.insert ( (tree.begin()+pos+1), novo );

    return (float)(m+mm)/(n+nn);
    /*
       }

       pos = (pos+b)/2;
       m = tree [pos].first;
       n = tree [pos].second;

       return m/n;
       */
}

float addTreeLeft ( vector < pair < int, int > >& tree, int pos, int b )
{
    int m, n, mm, nn;
    /*
       if ( tree [pos-1].first == 0 )
       {
       */
    m = tree [pos].first;
    n = tree [pos].second;
    mm = tree [pos-1].first;
    nn = tree [pos-1].second;


    pair < int, int > novo ( m+mm, n+nn );

    tree.insert ( (tree.begin()+pos), novo );

    return (float)(m+mm)/(n+nn);
    /*
       }

       pos = (pos+b)/2;
       m = tree [pos].first;
       n = tree [pos].second;

       return m/n;
       */
}

int growV ( vector < pair < int, int > >& tree, float val )
{
    int m, mm, nn, n;
    int pos = 0;
    float f;
    vector < pair < int, int > > t2;
    for ( int i = 0; i < tree.size()-1; i++ )
    {
        m = tree [pos].first;
        n = tree [pos].second;
        mm = tree [pos+1].first;
        nn = tree [pos+1].second;
        pair < int, int > novo ( m+mm, n+nn );
        f = (float)(m)/(n);

        if ( f < val )
        {
            pos++;
        }
        t2.push_back ( tree[pos] );
        t2.push_back ( novo );
    }

    tree = t2;

    return pos;
}


void searchTree ( float aim ) 
{
    float val = 1.0;
    int rm = 1;
    int rn = 0;
    int lm = 0;
    int ln = 1;
    int m = 1;
    int n = 1;
    //    printf ( "aim = %f val=%f\n", aim, val );

    while ( aim != val )
    {
//        printf ( "%d/%d %d/%d %d/%d val = %f\n", lm, ln, m, n, rm, rn, val );
//        getchar();
        if ( aim > val )
        {
            lm = m;
            ln = n;
            m += rm;
            n += rn;

            val = (float)m/n;
            printf ( "R" );
        }
        else 
        {
            rm = m;
            rn = n;
            m += lm;
            n += ln;

            val = (float)m/n;
            printf ( "L" );
        }
    }

    printf ("\n");
}

void searchTree2 ( vector < pair < int, int > >& tree, float aim ) 
{
    float val = 1.0;
    int b = tree.size();
    int pos = tree.size() >> 1;
    int a = 0;
    //    printf ( "aim = %f val=%f\n", aim, val );

    while ( aim != val )
    {
        //   getchar();
        //printf ( "\nval = %f pos=%d a=%d b=%d\n", val, pos, a, b );
        //    printf ( "val = %f ", val );
        if ( aim > val )
        {
            /*
               a = pos;
               pos = (a + b)/2;
               */
            val = addTreeRight ( tree, pos, b);
            pos++;
            //val = (float)tree[pos].first / tree[pos].second;
            printf ( "R" );
        }
        else 
        {
            /*
               b = pos;
               pos = (a + b)/2;
               */
            //pos--;
            val = addTreeLeft ( tree, pos, b);
            //val = (float)tree[pos].first / tree[pos].second;
            printf ( "L" );
        }
        /*
           for ( int i = 0; i < tree.size(); i++ )
           {
           printf ( "%d/%d ", tree[i].first, tree[i].second );
           }
           */
    }

    printf ("\n");
}

list < pair < int, int > > grow ( list < pair < int, int > > tree )
{
    list < pair < int, int > > ans;
    int m, n, mm, nn;
    list < pair < int, int > >::iterator i;
    list < pair < int, int > >::iterator li = tree.begin();
    list < pair < int, int > >::iterator end = tree.end();
    end--;

    //    for ( int i = 0; i < tree.size()-1; i++ )

    for ( i = tree.begin(); i != end; i++ )
    {
        li++;
        ans.push_back ( *i );
        m = (*i).first;
        n = (*i).second;
        mm = (*li).first;
        nn = (*li).second;

        ans.push_back ( pair < int, int > (m+mm, n+nn) );
    }
    ans.push_back ( tree.back() );

    return ans;
}

int main ()
{
    list < pair < int, int > > tree;
    tree.push_back ( pair < int, int > (0,1) );
    tree.push_back ( pair < int, int > (1,0) );

    int max = 1;

    for ( int i = 0; i < max; i++ )
    {
        tree = grow ( tree ); 
    }

//    printList ( tree );


    /*
       addTreeLeft ( treeV, 1, 0 );
       addTreeRight ( treeV, 1, 3 );
       addTreeRight ( treeV, 2, 3 );
       addTreeRight ( treeV, 3, 4 );
       addTreeLeft ( treeV, 3, 2 );
       */

    /*
    vector < pair < int, int > > treeV ( tree.begin(), tree.end() );
    for ( int i = 0; i < treeV.size(); i++ )
    {
        printf ( "%d/%d ", treeV[i].first, treeV[i].second );
    }
    printf ( "\n" );
    growV ( treeV, 0 );
    for ( int i = 0; i < treeV.size(); i++ )
    {
        printf ( "%d/%d ", treeV[i].first, treeV[i].second );
    }
    printf ( "\n" );
    growV ( treeV, 0 );
    for ( int i = 0; i < treeV.size(); i++ )
    {
        printf ( "%d/%d ", treeV[i].first, treeV[i].second );
    }
    */

    int um, dois;
    while ( scanf ( " %d %d", &um, &dois ) == 2 )
    {
        if ( um == 1 && dois ==1 )
        {
            break;
        }
        //vector < pair < int, int > > treeV ( tree.begin(), tree.end() );
        float f = (float)um/dois;
        searchTree ( f );
    }

    return 0;
}
