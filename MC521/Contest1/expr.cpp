#include <iostream>
#include <stack>

using namespace std;

int main ()
{
    string s;
    int n;
    char ans;
    int obracket = 0;
    int oparen = 0;
    int ocurly = 0;
    stack < char > lookahead;

    cin >> n;
    getline (cin, s);

    for ( int i = 0; i < n; i++ )
    {
        ans = 'S';
        obracket = 0;
        oparen = 0;
        ocurly = 0;
        getline (cin, s);

        for ( int j = 0; j < s.size() && ans == 'S'; j++ )
        {
            //cout << "--" << s[j] << "--" << endl;
            switch ( s[j] )
            {
                case '{':
                    {
                        lookahead.push('}');
                        ocurly++;
                        break;
                    }
                case '[':
                    {
                        lookahead.push(']');
                        obracket++;
                        break;
                    }
                case '(':
                    {
                        lookahead.push(')');
                        oparen++;
                        break;
                    }
                case ')':
                    {
                        if ( lookahead.empty() )
                        {
                            ans = 'N';
                            break;
                        }

                        if (--oparen < 0 || lookahead.top() != ')' )
                        {
                            ans = 'N';
                        }
            lookahead.pop();
                        break;
                    }
                case '}':
                    {
                        if ( lookahead.empty() )
                        {
                            ans = 'N';
                            break;
                        }
                        if (--ocurly < 0 || lookahead.top() != '}' )
                        {
                            ans = 'N';
                        }
            lookahead.pop();
                        break;
                    }
                case ']':
                    {
                        if ( lookahead.empty() )
                        {
                            ans = 'N';
                            break;
                        }
                        if (--obracket < 0 || lookahead.top() != ']' )
                        {
                            ans = 'N';
                        }
            lookahead.pop();
                        break;
                    }
            }

        }
            if ( obracket || ocurly || oparen )
            {
                ans = 'N';
            }
        //cout << obracket << " " << oparen << " " << ocurly << endl;
        cout << ans << endl;
    }


    return 0;
}
