#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    long long int n, S, p, idx, k=0, T=inf, curr ;
    cin>> n >> S ;
    vlli a(n+1), b(n+1) ;
    for(int i=1 ; i<=n ; i++)
      cin>> a[i] ;
    long long int l=0, r=n, m ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        for(int i=1 ; i<=n ; i++)
          b[i]=a[i]+m*i ;
        sort(b.begin()+1, b.end()) ;
        curr=0 ;
        for(int i=1 ; i<=m ; i++)
          curr+=b[i] ;
        if(curr<=S)
          {
            if(m>k)
              {
                k=m ;
                T=curr ;
                l=m+1 ;
              }
            else if(m==k)
              {
                if(curr<T) T=curr ;
                l=m+1 ;
              }
          }
        else r=m-1 ;
      }
    if(k==0) cout<< 0 << " " << 0 ;
    else cout<< k << " " << T ;
  }
