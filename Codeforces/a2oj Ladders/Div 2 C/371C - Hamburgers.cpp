#include <bits/stdc++.h>
using namespace std ;

int nb, ns, nc, pb, ps, pc, ans=0, cb=0, cs=0, cc=0 ;
long long int r ;

long long int bs()
  {
    long long int x, l, m, u, ans=0 ;
    l=0 ; u=1000000000000+110 ;
    while(l<=u)
      {
        m=(l+u)/2 ;
        x=max((long long)0, cb*m-nb)*pb + max((long long)0, cs*m-ns)*ps + max((long long)0, cc*m-nc)*pc ;
        if(x<=r)
          {
            l=m+1 ;
            ans=max(ans, m) ;
          }
        else u=m-1 ;
      }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    string s ;
    cin>> s >> nb >> ns >> nc >> pb >> ps >> pc >> r ;
    for(int i=0 ; i<s.length() ; i++)
      if(s[i]=='B') cb++ ;
      else if(s[i]=='S') cs++ ;
      else cc++ ;
    cout<< bs() ;
  }
