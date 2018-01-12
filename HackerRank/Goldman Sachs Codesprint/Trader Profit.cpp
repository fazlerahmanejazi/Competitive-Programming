#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int n, k, ans ;
vi a ;

void solve(int idx, int done, int curr, bool end)
  {
    if(end) ans=max(curr, ans) ;
    if(done==k || idx>=n-1) return ;
    if(end)
      for(int i=idx ; i<n ; i++)
        solve(i, done, curr, false) ;
    else
      for(int i=idx ; i<n ; i++)
        if(a[i]>a[idx])
          solve(i+1, done+1, curr+a[i]-a[idx], true) ;

  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> k >> n ;
        a.clear() ; a.resize(n) ;
        ans=0 ;
        for(int i=0 ; i<n ; i++)
          cin>> a[i] ;
        for(int i=0 ; i<n-1 ; i++)
          solve(i, 0, 0, false) ;
        cout<< ans << endl ;
      }
  }
