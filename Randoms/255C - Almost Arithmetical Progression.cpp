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
    int n, ans=-1, c=1 ;
    cin>> n ;
    vi seq(n) ;
    set<int> cnv ;
    map<int, int> M ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> seq[i] ;
        cnv.insert(seq[i]) ;
      }
    auto it=cnv.begin() ;
    while(it!=cnv.end())
      {
        M[*it]=c++ ;
        it++ ;
      }
    for(int i=0 ; i<n ; i++)
      seq[i]=M[seq[i]] ;
    int dp[n+1][c+1] ;
    memset(dp, 0, sizeof dp) ;
    for(int i=0 ; i<n ; i++)
      dp[i][0]=1 ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<i ; j++)
        dp[i][seq[j]]=max({dp[i][seq[j]], dp[j][seq[i]]+1, dp[j][0]+1}) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<c ; j++)
        ans=max(ans, dp[i][j]) ;
    cout<< ans ;
  }
