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
    int T, n ;
    bool pos, prime[300], semiPrime[100000] ;
    memset(prime, true, sizeof prime) ;
    memset(semiPrime, false, sizeof semiPrime) ;
    prime[1]=false ;
    for(int i=2 ; i<=200 ; i++)
      if(prime[i])
        for(int j=2*i ; j<=200 ; j+=i)
          prime[j]=false ;
    for(int i=1 ; i<=200 ; i++)
      for(int j=1 ; j<=200 ; j++)
        if(i!=j && prime[i] && prime[j])
          semiPrime[i*j]=true ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        pos=false ;
        for(int i=1 ; i<n ; i++)
          if(semiPrime[i] && semiPrime[n-i])
            pos=true ;
        if(pos) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
  }
