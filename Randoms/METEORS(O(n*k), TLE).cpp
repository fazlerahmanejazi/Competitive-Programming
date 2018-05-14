#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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

lli n, m, k, l, r, val ;
vlli state, req, curr, ans ;
vector<pair<pii, lli>> meteor ;
vb done ;

void update()
  {
    if(l<=r)
      for(int i=l ; i<=r ; i++)
        curr[state[i]]+=val ;
    else
      {
        for(int i=l ; i<=m; i++)
          curr[state[i]]+=val ;
        for(int i=1 ; i<=r; i++)
          curr[state[i]]+=val ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    state.resize(m+1) ; req.resize(n+1) ; meteor.resize(n+1) ;
    curr.assign(n+1, 0) ; done.assign(n+1, false) ; ans.assign(n+1, -1) ;
    for(int i=1 ; i<=m ; i++)
      cin>> state[i] ;
    for(int i=1 ; i<=n ; i++)
      cin>> req[i] ;
    cin>> k ;
    for(int i=1 ; i<=k ; i++)
      {
        cin>> l >> r >> val ;
        update() ;
        for(int j=1 ; j<=n ; j++)
          if(!done[j] && curr[j]>=req[j])
            {
              done[j]=true ;
              ans[j]=i ;
            }
      }
    for(int i=1 ; i<=n ; i++)
      if(ans[i]==-1) cout<< "NIE" << endl ;
      else cout<< ans[i] << endl ;
  }
