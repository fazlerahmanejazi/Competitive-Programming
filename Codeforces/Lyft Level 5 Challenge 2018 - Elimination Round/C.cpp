#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
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
    int n, idx, cnt ;
    cin>> n ;
    vi a(n+1), pos(n+1), ans(n+1, 0) ;
    for(int i=1 ; i<=n ; i++) cin>> a[i], pos[a[i]]=i ;
    for(int i=n-1 ; i>=1 ; i--)
      {
        idx=pos[i]+i ;
        while(idx<=n)
          {
            if(a[idx]>i && !ans[a[idx]]) ans[i]=1 ;
            idx+=i ;
          }
        idx=pos[i]-i ;
        while(idx>=1)
          {
            if(a[idx]>i && !ans[a[idx]]) ans[i]=1 ;
            idx-=i ;
          }
      }
    for(int i=1 ; i<=n ; i++)
      if(ans[a[i]]) cout<< 'A' ;
      else cout<< 'B' ;
  }
