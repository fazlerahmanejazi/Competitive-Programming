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

int n, m, u, v, x, ans, dist[100], type[100], dp[100][100], w[100][100] ;
map<int, int> cnt ;
set<int> temp ;

bool check(int x)
  {
    return (temp.find(x)!=temp.end()) ;
  }

void floyd()
  {
    for(int k=0 ; k<n ; k++)
      for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
          dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]) ;
  }

int calculate()
  {
    priority_queue<tuple<int, int, int>> pq ;
    for(int i=0 ; i<n ; i++)
      for(int j=i+1 ; j<n ; j++)
        pq.push(mt(-dist[i][j], i, j))
    int res=0 ;
    temp.clear() ;
    while(tenp.size()!=n)
      {
        tie(x, u, v)=pq.top() ; pq.pop() ;
        if(check(u) && check(v)) continue ;
        else if(check(u) || check(v)) ans-=x ;
        else ans-=2*x ;
      }
    return ans ;
  }

void buildGraph(int T)
  {
    memset(dp, inf, sizeof dp) ;
    memset(dist, inf, sizeof dist) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        if(i!=j) dp[i][j]=w[i][j] ;
        else dp[i][j]=0 ;
    floyd() ;
    calculate() ;
  }

void solve()
  {
    cnt.clear() ;
    for(int i=1 ; i<(1<<n)-1 ; i++)
      {
        buildGraph(i) ;
        int curr=0 ;
        for(int j=0 ; j<n ; j++) if(dist[j]==inf) curr=-1 ;
        if(curr==-1) continue ;
        for(int j=0 ; j<n ; j++) curr+=dist[j] ;
        cnt[curr]++ ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        memset(w, inf, sizeof w) ;
        cin>> n >> m ;
        for(int i=0 ; i<m ; i++)
          {
            cin>> u >> v >> x ;
            w[u-1][v-1]=w[v-1][u-1]=x ;
          }
        solve() ;
        ans=(*cnt.begin()).se ;
        cout<< "Case #"<< tc << ": "<< ans << endl ;
      }
  }
