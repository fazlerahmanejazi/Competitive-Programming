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

long double calc(long double x, long double y)
  {
    return (2*(x+y)*(x+y))/(x*y) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        lli n, x, cnt[10010] ;
        long double curr, mn=INF ;
        vlli a, ans ;
        set<lli> temp ;
        memset(cnt, 0, sizeof cnt) ;
        cin>> n ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> x ;
            cnt[x]++ ;
            if(cnt[x]>=2) temp.insert(x) ;
            if(cnt[x]>=4)
              {
                ans.pb(x) ;
                ans.pb(x) ;
                ans.pb(x) ;
                ans.pb(x) ;
              }
          }
        a.assign(temp.begin(), temp.end()) ;
        if(ans.empty())
          for(int i=1 ; i<a.size() ; i++)
            {
              curr=calc(a[i], a[i-1]) ;
              if(curr<mn)
                {
                  ans.clear() ;
                  ans.pb(a[i]) ;
                  ans.pb(a[i]) ;
                  ans.pb(a[i-1]) ;
                  ans.pb(a[i-1]) ;
                  mn=curr ;
                }
            }
        for(int i=0 ; i<4 ; i++) cout<< ans[i] << " " ;
        cout<< endl ;
      }
  }
