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

int n, k, g[50], f[50] ;

void reconstruct(int n, int k)
  {
    if(!n) return ;
    if(k<=g[n]) cout<< 0, reconstruct(n-1, k) ;
    else cout<< 1, reconstruct(n-1, k-g[n]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    g[1]=f[1]=1 ;
    for(int i=2 ; i<=44 ; i++)
      {
        g[i]=g[i-1]+f[i-1] ;
        f[i]=g[i-1] ;
      }
    if(k>g[n]+f[n]) cout<< -1 ;
    else reconstruct(n, k) ;
  }
