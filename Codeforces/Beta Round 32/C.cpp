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
    lli n, m, s, ans ;
    cin>> n >> m >> s ;
    if(!((n-1)/s) && !((m-1)/s)) ans=n*m ;
    else if(!((n-1)/s)) ans=((m+s-1)/s)*(n*((m-1)%s+1)) ;
    else if(!((m-1)/s)) ans=((n+s-1)/s)*(m*((n-1)%s+1)) ;
    else ans=(((n+s-1)/s)*((m+s-1)/s))*(((m-1)%s+1)*((n-1)%s+1)) ;
    cout<< ans ;
  }
