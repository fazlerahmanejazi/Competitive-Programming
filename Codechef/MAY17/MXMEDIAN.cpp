#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    int T, n, m, ans ;
    cin>> T ;
    while(T--)
      {
        cin>> m ;
        n=2*m ;
        vector<int> A(n+1) ;
        for(int i=1 ; i<=n ; i++)
          cin>> A[i] ;
        sort(A.begin()+1, A.end()) ;
        ans=A[m+ceil(m/2.0)] ;
        cout<< ans << endl ;
        for(int i=1 ; i<m ; i++)
            cout<< A[i] << " " << A[m+i] << " " ;
        cout<< A[m] << " " << A[2*m] << endl ;
      }
  }
