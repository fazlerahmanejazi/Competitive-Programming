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

bool cmp(pair<lli, lli> x, pair<lli, lli> y)
  {
    if(x.fi!=y.fi) return x.fi<y.fi ;
    else if(x.fi==y.fi) return x.se>y.se ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, l, r, x, cnt=0, prev=-1 ;
    vector<pair<lli, lli>> a ;
    cin>> n ;
    vlli ans(n+1, 0) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> l >> r ;
        a.pb(mp(l, 1)) ;
        a.pb(mp(r, -1)) ;
      }
    sort(all(a), cmp) ;
    for(auto i:a)
      if(i.se==1)
        {
          ans[cnt]+=i.fi-prev ;
          cnt++ ;
          prev=i.fi ;
        }
      else
        {
          ans[cnt]+=i.fi-prev+1 ;
          cnt-- ;
          prev=i.fi+1 ;
        }
    for(int i=1 ; i<=n ; i++) cout<< ans[i] << " " ;
  }
