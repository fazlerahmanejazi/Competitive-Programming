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

int n, m, p[5000000], a[5000000], ans ;

int find(int i)
  {
    if(i!=p[i]) p[i]=find(p[i]) ;
    return p[i] ;
  }

bool same(int i, int j)
  {
    return find(i)==find(j) ;
  }

void unionset(int i, int j)
  {
    int x=find(i) ; int y=find(j) ;
    if(x!=y) p[x]=y ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    for(int i=0 ; i<=5000000 ; i++) p[i]=i ;
    cin>> n >> m ;
    for(int i=1 ; i<=m ; i++) cin>> a[i] ;
    for(int i=22 ; i>=0 ; i--)
      {
        vi idx ;
        for(int j=1 ; j<=n ; j++)
          if((a[j]&(1<<i)))
            idx.pb(j) ;
        for(int j=1 ; j<idx.size() ; j++) unionset(idx[j], idx[0]) ;
      }
    for(int i=1 ; i<=n ; i++) if(find(i)==i) ans++ ;
    cout<< ans ;
  }
