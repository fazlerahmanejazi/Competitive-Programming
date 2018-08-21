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

int n, x, ans ;
vb isprime(410, true) ;
int g[110][110] ;

void sieve()
  {
    isprime[1]=false ;
    for(int i=2 ; i<=400 ; i++)
      if(isprime[i])
        for(int j=i+i ; j<=400 ; j+=i)
          isprime[j]=false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    sieve() ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=n ; j++)
        cin>> g[i][j] ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=n ; j++)
        {
          x=g[i-1][j]+g[i+1][j]+g[i][j-1]+g[i][j+1] ;
          if(isprime[x])
            ans++ ;
        }
    cout<< ans ;
  }
