#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    int n, k, c=1, m ;
    cin>> n >> k ;
      {
        if(n==2)
          {
            if(!k) cout<< -1 ;
            else cout<< 1 << " " << 2 << " " << 1 ;
           }
        else if(n==3 && !k) cout<< -1 ;
        else
          {
            m=2*(n-1)-k ;
            cout<< m << endl ;
            int u, v ;
            for(int i=n ; i>1 ; i--, m--) cout<< i << " " << i-1 << " " << c++ << endl ;
            u=max(k, 1), v=u+2 ;
            while(m--)
              {
                cout<< u << " " << v << " " << c++ << endl ;
                v++ ;
                if(v>n) u+=1, v=u+2 ;
              }
          }
      }
  }
