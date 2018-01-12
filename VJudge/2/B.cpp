#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, A, B, curr, l, r, m, cnt, ans ;
    cin>> n >> A >> B ;
    vlli h(n+1) ;
    for(int i=1 ; i<=n ; i++)
      cin>> h[i] ;
    sort(h.begin()+1, h.end()) ;
    A-=B ;
    l=1 ; r=h[n]*A ;
    ans=r ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        cnt=0 ;
        for(int i=1 ; i<=n ; i++)
          {
            curr=max(0LL, h[i]-B*m) ;
            cnt+=ceil(curr/(1.0*A)) ;
          }
        if(cnt<=m)
          {
            r=m-1 ;
            ans=min(ans, m) ;
          }
        else l=m+1 ;
      }
    cout<< ans ;
  }
