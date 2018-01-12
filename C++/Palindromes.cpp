#include <bits/stdc++.h>
using namespace std ;
int main()
{
    string s ;
    while(cin>> s)
     {
        int len = s.length() ;
        int i, j;
        char a[] = "A   3  HIL JM O   2TUVWXY5";
        char b[] = "01SE Z  8 ";
        int f1 = 0, f2 = 0;
        for(i = 0, j = len-1; i <= j; i++, j--) {
            if(s[i] != s[j])
                f1 = 1;
            if(s[i] >= 'A' && s[i] <= 'Z') {
                if(s[j] != a[s[i]-'A'])
                    f2 = 1;
            } else {
                if(s[j] != b[s[i]-'0'])
                    f2 = 1;
            }
        }
        cout<<s << " -- is " ;
        if(f1) {
            if(f2)
                cout << "not a palindrome.";
            else
                cout<< "a mirrored string.";
        } else {
            if(f2)
                cout<< "a regular palindrome.";
            else
                cout<< "a mirrored palindrome.";
        }
        cout<< endl << endl ;
    }
    return 0;
}
