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
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        int n, d=1 ;
        cin>> n ;
        vi ans(n, 0), idx(n, 0) ;
        vpii  a(n), b ;
        for(int i=0 ; i<n ; i++) idx[i]=i ;
        for(int i=0 ; i<n ; i++) cin>> a[i].fi, a[i].se=i ;
        for(int i=1 ; i<n ; i++)
          if(a[i]==a[i-1]) idx[i]=idx[idx[i-1]] ;
          else b.pb(a[i]) ;
        while(!a.empty())
          {
            n=a.size() ;
            b.clear() ;
            b.pb(a[0]) ;
            if(n>=3)
              for(int i=1 ; i<n-1 ; i++)
                if(a[i].fi>=min(a[i-1].fi, a[i+1].fi)) b.pb(a[i]) ;
                else ans[a[i].se]=d ;
            if(n>1) b.pb(a[n-1]) ;
            d++ ;
            if(a==b) break ;
            a=b ;
          }
        for(int i=0 ; i<n ; i++) cout<< ans[idx[i]] << " " ;
        cout<< endl ;
      }
  }
