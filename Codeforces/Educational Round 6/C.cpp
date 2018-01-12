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

int n, idx, last, ans ;
vi a ;
vpii res ;
map<int, int> cnt ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.resize(n+1) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a[i] ;
        cnt[a[i]]++ ;
        if(cnt[a[i]]==2) ans=1 ;
      }
    cnt.clear() ;
    if(!ans) cout<< -1 ;
    else
      {
        last=0 ; idx=-1 ;
        while(idx<n-1)
          {
            idx++ ;
            cnt[a[idx]]++ ;
            if(cnt[a[idx]]==2) res.pb(mp(last+1, idx+1)), last=idx+1, cnt.clear() ;
          }

        if(last!=n) res[res.size()-1].se=n ;
        cout<< res.size() << endl ;
        for(int i=0 ; i<res.size() ; i++) cout<< res[i].fi << " " << res[i].se << endl ;
      }
  }
