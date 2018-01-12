#include <bits/stdc++.h>
using namespace std ;
int main()
{ string s[53],q[53] ;
  int n, a[53], y=0,c=0 ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
   {
    for(int j=1 ; j<53 ; j++)
    { cin>> s[j] ;
      if(s[j][0]>= '2' && s[j][0]<= '9') a[j]=stoi(s[j].substr(0,1)) ;
      else a[j]=10 ;
    }
    int m ;
    for(int m=27 ; m>0 ; m--)
    {
      y=y+a[m] ;
      m=m-(10-a[m]) ;
      c++ ;
      if(c==3) {m=m-1 ; break ;}
    }
    for(int j=1 ; j<=25 ; j++)
    {  s[m+j]=s[27+j] ;
    }
    cout<< "Case" << i+1 << ":" << s[y] ;
  }
    return 0 ;
}
