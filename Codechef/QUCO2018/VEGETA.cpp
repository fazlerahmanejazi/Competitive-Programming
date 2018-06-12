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

lli n, m, ans ;
vlli cnt ;

void seive()
  {
    cnt.assign(1e6+100, 0) ;
    for(int i=2 ; i<=1e6 ; i++)
      if(!cnt[i])
        for(int j=i ; j<=1e6 ; j+=i)
          cnt[j]++ ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    seive() ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> m ;
        ans=0 ;
        for(int j=n ; j<m ; j++) ans+=cnt[j] ;
        cout<< ans << endl ;
      }
  }
