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

lli n, m, u, v, w, x, net[2000000] ;
vector<tuple<lli, lli, lli>> ans ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=m ; i++)
      {
        cin>> u >> v >> w ;
        net[u]-=w ;
        net[v]+=w ;
      }
    vector<pair<lli, lli>> neg ;
    priority_queue<pair<lli, lli>> pos ;
    for(int i=1 ; i<=n ; i++)
      if(net[i]>0) pos.push(mp(net[i], i)) ;
      else if(net[i]<0) neg.pb(mp(-net[i], i)) ;
    sort(all(neg)) ;
    reverse(all(neg)) ;
    for(int i=0 ; i<neg.size() ; i++)
      {
        tie(w, u)=neg[i] ;
        while(w>0)
          {
            tie(x, v)=pos.top() ; pos.pop() ;
            lli minm=min(w, x) ;
            ans.pb(mt(u, v, minm)) ;
            w-=minm ;
            x-=minm ;
            if(x>0) pos.push(mp(x, v)) ;
          }
      }
    cout<< ans.size() << endl ;
    for(auto i:ans)
      {
        tie(u, v, w)=i ;
        cout<< u << " " << v << " " << w << endl ;
      }
  }
