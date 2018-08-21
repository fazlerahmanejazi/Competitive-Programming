#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    string left, right ;
    string s ;
    int a, b, n, x ;
    bool possible=false ;
    cin>> s ;
    cin>> a >> b ;
    n=s.length() ;
    vector<int> r(n+2), l(n+2) ;
    l[0]=0 ;
    for(int i=0 ; i<n ; i++)
      l[i+1]=(l[i]*10+s[i]-'0')%a ;
    r[n+1]=0 ;
    x=1 ;
    for(int i=n-1 ; i>=0 ; i--)
      {
        r[i+1]=((s[i]-'0')*x+r[i+2])%b ;
        x=(x*10)%b ;
      }
    for(int i=1 ; i<n ; i++)
      if(!l[i] && !r[i+1] && s[i]!='0')
        {
          possible=true ;
          left=s.substr(0, i) ;
          right=s.substr(i, n-i) ;
          break ;
        }
    if(possible)
      {
        cout<< "YES" << endl ;
        cout<< left << endl << right ;
      }
    else cout<< "NO" ;
  }
