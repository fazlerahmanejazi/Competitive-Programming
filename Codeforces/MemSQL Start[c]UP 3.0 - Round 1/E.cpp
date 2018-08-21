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

lli n, a, b, loops, cycles, ans=1 ;
vi p, avail ;
vlli cnt ;

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
    cin>> n ;
    p.resize(2*n+1) ;
    cnt.assign(2*n+1, 1) ;
    avail.assign(2*n+1, -1) ;
    for(int i=1 ; i<=2*n ; i++) p[i]=i ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a >> b ;
        if(avail[a]==-1) avail[a]=1 ; if(avail[b]==-1) avail[b]=1 ;
        if(a==b) avail[a]=0, loops++ ;
        else if(same(a, b)) avail[find(a)]=0, cycles++ ;
        else
          {
            int x=cnt[find(a)], y=cnt[find(b)], z=(avail[find(a)]*avail[find(b)]) ;
            unionset(a, b) ;
            avail[find(a)]=z ;
            cnt[find(a)]=x+y ;
          }
      }
    for(int i=1 ; i<=cycles ; i++) ans=(ans*2)%mod ;
    for(int i=1 ; i<=2*n ; i++)
      if(avail[find(i)])
        ans=(ans*cnt[find(i)])%mod, avail[find(i)]=0 ;
    cout<< ans ;
  }
