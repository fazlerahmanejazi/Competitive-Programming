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
    lli n, T, x, y, t, mx=-1, res=0 ;
    cin>> n >> T ;
    vlli cnt(1000010, 0), ans(1000010, 0) ;
    for(int i=0 ; i<n ; i++) cin>> x, cnt[x]++ ;
    /*for(int i=1 ; i<=T ; i++)
      for(int j=1 ; j<=sqrt(i) ; j++)
        if(!(i%j))
          {
            if(i/j==j) ans[i]+=cnt[j] ;
            else ans[i]+=(cnt[i/j]+cnt[j]) ;
          }*/
    for(int i=1 ; i<=T ; i++)
      for(int j=i ; j<=T ; j+=i)
        ans[j]+=cnt[i] ;
    for(int i=1 ; i<=T ; i++) mx=max(mx, ans[i]) ;
    for(int i=1 ; i<=T ; i++) if(ans[i]==mx) res++ ;
    cout<< mx << " " << res ;
  }
