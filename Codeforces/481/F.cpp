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
    int n, k, x, y, curr=0 ;
    cin>> n >> k ;
    vpii r ;
    map<int, int> skill, taken ;
    vi cnt(n+1, 0), ans(n+1) ;
    for(int i=0 ; i<n ; i++) cin>> x, r.pb(mp(x, i+1)), skill[i+1]=x ;
    for(int i=0 ; i<k ; i++)
      {
        cin>> x >> y ;
        if(skill[x]>skill[y]) cnt[x]++ ;
        else if(skill[x]<skill[y]) cnt[y]++ ;
      }
    sort(all(r)) ;
    for(int i=0 ; i<n ; i++)
      {
        ans[r[i].se]=max(i-cnt[r[i].se]-taken[r[i].fi], 0) ;
        taken[r[i].fi]++ ;
      }
    for(int i=1 ; i<=n ; i++) cout<< ans[i] << " " ;
  }
