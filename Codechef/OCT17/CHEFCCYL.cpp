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

int T, n, q, x, w, v1, v2, c1, c2 ;
vi bridge, extra ;
vvi cycle, cTwo, a ;
vector<tuple<int, int, int>> cnc ;

void init()
  {
    cycle.clear() ; cTwo.clear() ; a.clear() ;
    cnc.clear() ; extra.clear() ; bridge.clear() ;
    cycle.resize(n+1) ; cTwo.resize(n+1) ; a.resize(n+1) ;
    cnc.resize(n+1) ; extra.resize(n+1) ;
    bridge.assign(n+1, 0) ;
  }

int dist(int x, int y, int idx)
  {
    if(x>y) swap(x, y) ;
    x-- ; y-- ;
    int tot=cycle[idx][cycle[idx].size()-1] ;
    return min(cycle[idx][y]-cycle[idx][x], tot-cycle[idx][y]+cycle[idx][x]) ;
  }

int getOther(int idx, int v)
  {
    if(cTwo[idx][0]==v) return cTwo[idx][1] ;
    else return cTwo[idx][0] ;
  }

int query(int x, int y, int v1, int v2)
  {
    int tot=bridge[n]+extra[n], a, b, u1, u2 ;
    if(x>y) swap(x, y), swap(v1, v2) ;
    u1=get<0>(cnc[x]) ; u2=get<1>(cnc[y-1]) ;
    x-- ; y-- ;
    a=bridge[y]-bridge[x]+extra[y]-extra[x+1]+dist(v1, u1, x+1)+dist(v2, u2, y+1) ;
    u1=getOther(x+1, u1) ; u2=getOther(y+1, u2) ;
    b=tot-bridge[y]+bridge[x]-extra[y+1]+extra[x]+dist(v1, u1, x+1)+dist(v2, u2, y+1) ;
    return min(a, b) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> q ;
        init() ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> x ;
            cycle[i].assign(x+1, 0) ;
            for(int j=1 ; j<=x ; j++)
              {
                cin>> cycle[i][j] ;
                cycle[i][j]+=cycle[i][j-1] ;
              }
          }
        for(int i=1 ; i<=n ; i++)
          {
            cin>> v1 >> v2 >> w ;
            cnc[i]=mt(v1, v2, w) ;
            bridge[i]=w+bridge[i-1] ;
            cTwo[i].pb(v1) ;
            cTwo[(i%n)+1].pb(v2) ;
          }
        cnc[0]=cnc[n] ;
        for(int i=1 ; i<=n ; i++)
          {
            v1=get<0>(cnc[i]) ; v2=get<1>(cnc[i-1]) ;
            extra[i]=dist(v1, v2, i)+extra[i-1] ;
          }
        for(int i=1 ; i<=q ; i++)
          {
            cin>> v1 >> c1 >> v2 >> c2 ;
            cout<< query(c1, c2, v1, v2) << endl ;
          }
      }
  }
