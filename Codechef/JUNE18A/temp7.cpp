#include <bits/stdc++.h>
using namespace std ;

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
    seive() ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> n >> c ;
        N=min(n+1, 30LL) ;
        factorize(c) ;
        L=factors.size() ;
        for(int i=1 ; i<N ; i++) temp[i]=i-1, ans[i]=INF ;
        temp[N]=ans[N]=INF ;
        for(int i=1 ; i<=N ; i++) vals[i]=1 ;
        solve(0, 1) ;
        for(int i=1 ; i<N ; i++) cout<< ans[i] << " " ;
        cout<< endl ;
      }
  }
