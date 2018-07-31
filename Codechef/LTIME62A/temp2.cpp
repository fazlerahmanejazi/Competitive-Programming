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

lli n, m, ans, a[25][100010] ;

void solve(int idx, lli curr, int cnt)
  {
    if(idx>n)
      {
        if(cnt>1) ans=(ans+curr)%mod ;
        return ;
      }
    solve(idx+1, curr, cnt) ;
    for(int i=1 ; i<=m ; i++)
      if(idx==1) solve(idx+1, a[idx][i], cnt+1) ;
      else solve(idx+1, __gcd(a[idx][i], curr), cnt+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        cin>> a[i][j] ;
    solve(1, 1, 0) ;
    cout<< ans ;
  }
