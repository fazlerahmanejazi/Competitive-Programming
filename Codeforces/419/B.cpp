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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, k, q, l, r ;
    cin>> n >> k >> q ;
    vi temp(200005, 0), dp(200005, 0) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> l >> r ;
        temp[l]++ ;
        temp[r+1]-- ;
      }
    for(int i=1 ; i<=200000 ; i++)
      temp[i]+=temp[i-1] ;
    for(int i=1 ; i<=200000 ; i++)
      dp[i]=dp[i-1]+(temp[i]>=k) ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> l >> r ;
        cout<< dp[r]-dp[l-1] << endl ;
      }
  }
