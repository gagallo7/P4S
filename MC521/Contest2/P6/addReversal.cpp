#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int reversal ( string s )
{
    string ans;
    int num;
    bool leading = true;
    for ( int i = s.size()-1; i >= 0; i-- )
    {
        if ( s[i] == 48 && leading == false )
        {
            ans += s[i];
            num *= 10;
        }
        else if ( s[i] > 48 )
        {
            leading = false;
            ans += s[i];
            num *= 10;
            num += s[i]-48;
        }
    }
    return num;
}

string addReversal2 ( string s1, string s2 )
{

    string sum;

    int size;
    if ( s1.size() > s2.size() )
    {
        size = s1.size();
    }
    else
    {
        size = s2.size();
    }

    int carry = 0;
    bool leading = true;
    for ( int i = 0; i < size; i++ )
    {
        char s = carry;

        if ( i < s1.size() )
        {
            s += s1[i];
        }
        if ( i < s2.size() )
        {
            s += s2[i];
        }

        if ( s > 58 )
        {
            s -= 48;
        }

        if ( s >= 58 )
        {
            s    -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        if ( s == '0' && !leading )
        {
            sum += s;
        }
        else if ( s > 48 )
        {
            sum    += s;
            leading = false;
        }
    }

    if ( carry )
    {
        sum += '1';
    }

    return sum;
}


string addReversal ( string s1, string s2 )
{
    string r1, r2;
    int num;
    bool leading = true;
    for ( int i = s1.size()-1; i >= 0; i-- )
    {
        if ( s1[i] == 48 && leading == false )
        {
            r1 += s1[i];
            num *= 10;
        }
        else if ( s1[i] > 48 )
        {
            leading = false;
            r1 += s1[i];
            num *= 10;
            num += s1[i]-48;
        }
    }

    leading = true;
    for ( int i = s2.size()-1; i >= 0; i-- )
    {
        if ( s2[i] == 48 && leading == false )
        {
            r2 += s2[i];
            num *= 10;
        }
        else if ( s2[i] > 48 )
        {
            leading = false;
            r2 += s2[i];
            num *= 10;
            num += s2[i]-48;
        }
    }

    cout << r1 << "  " << r2 << " --- " << (int)r2[8] <<  endl;

        int i = r1.size()-1;
        int j = r2.size()-1;

    string sum;

    cout << "size: " << i << " "  << j << endl ;

    leading = true;
    int carry = 0;
    while ( i >= 0 || j >= 0 )
    {
        char s = carry;
        if ( i >= 0 )
            s += r1[i];
        if ( j >= 0 )
            s += r2[j];
        s -= 48;

        //cout << s;
        if ( s == 48 && leading == false )
        {
            sum += s;
        }
        else if ( s > 48 )
        {
            if ( s >= 58 )
            {
                carry = 1;
                s -= 10;
            }
            else
            {
                carry = 0;
            }
            leading = false;
            sum += s;
        }
//        cout << s;
        if ( i >= 0 )
            i--;
        if ( j >= 0 )
            j--;
    }

    if ( carry )
    {
        sum += '1';
    }

    cout << endl ;

    return sum;
}

string rtstr ( int num )
{
    string ans;
    int mod = 10;
    int div = 1;
    int cpy =num;
    bool leading = true;

    if ( !num )
    {
        ans += 48;
        return ans;
    }

    while ( cpy >= div )
    {
        num %= mod;
        num /= div;

        if ( !leading && num == 0 )
        {
            ans += (num + 48);
        }
        else if ( num > 0 )
        {
            leading = false;
            ans += (num + 48);
        }


        div  = mod;
        mod *= 10;
        num  = cpy;
    }

    return ans;
}

int main ()
{
    //char a [201], b [201];
    string c;
    string d;
    int n;
    int sum;
//    cout << "aR: " << addReversal2 ( "123", "789" ) << endl;

    scanf ( " %d", &n );
    

    for ( int i = 0; i < n; i++ )
    {
      //  scanf ( " %[0-9] %[0-9]", c.data(), d.data() );
      //  scanf ( " %[0-9] %[0-9]", a, b );
      cin >> c >> d;
//      cout <<  c << " " << d;
  //    cout << reversal ( c ) << " " <<  reversal (d) << endl ;
      sum = reversal (c) + reversal (d);
//      cout << endl << "out >> " << sum << " " << "to Str: " << rtstr ( sum ) << endl;
      //cout << rtstr ( sum ) << endl;
      cout << addReversal2 ( c, d) << endl;
    }

    //printf ( " %s\n %s ", a, b );

    return 0;
}
