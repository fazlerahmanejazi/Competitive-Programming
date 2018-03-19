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
    int n, k, idx ;
    lli ans=0, cost ;
    cin>> n >> k ;
    vi c(n+1), ansT(n+1) ;
    for(int i=1 ; i<=n ; i++)
      cin>> c[i] ;
    priority_queue<pii> pq ;
    for(int i=1 ; i<=k ; i++)
      pq.push(mp(c[i], i)) ;
    for(int i=k+1 ; i<=n+k ; i++)
      {
        if(i<=n) pq.push(mp(c[i], i)) ;
        tie(cost, idx)=pq.top() ;
        pq.pop() ;
        ans+=cost*(i-idx) ;
        ansT[idx]=i ;
      }
    cout<< ans << endl ;
    for(int i=1 ; i<=n ; i++)
      cout<< ansT[i] << " " ;
  }
