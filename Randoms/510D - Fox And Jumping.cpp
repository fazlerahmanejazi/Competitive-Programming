#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
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

int gcd(int a, int b)
  {
    return b==0 ? a : gcd(b, a%b) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, curr ;
    cin>> n ;
    vi len(n), cost(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> len[i] ;
    for(int i=0 ; i<n ; i++)
      cin>> cost[i] ;
    map<int, int> dp ;
    dp[0]=0 ;
    for(int i=0 ; i<n ; i++)
      for(auto &x:dp)
        {
          curr=gcd(x.fi, len[i]) ;
          if(dp.find(curr)!=dp.end()) dp[curr]=min(dp[curr], x.se+cost[i]) ;
          else dp[curr]=x.se+cost[i] ;
        }
    if(dp.find(1)!=dp.end()) cout<< dp[1] ;
    else cout<< -1 ;
  }
