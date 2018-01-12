#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

vector<bool> isprime ;
vector<int> color ;
int ans=1 ;

void sieve(int n)
  {
    isprime.assign(n+10, true) ;
    isprime[0]=isprime[1]=false ;
    color.assign(n+10, 1) ;
    for(int i=2 ; i<=n ; i++)
      {
        if(isprime[i])
          {
            color[i]=1 ;
            for(int j=i+i ; j<=n ; j+=i)
              isprime[j]=false ;
          }
      }
    for(int i=2 ; i<=n+1 ; i++)
      if(!isprime[i])
        color[i]=2 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    cin>> n ;
    sieve(n+1) ;
    if(n<3) cout<< 1 << endl ;
    else cout<< 2 << endl ;
    for(int i=2 ; i<=n+1 ; i++)
      cout<< color[i] << " " ;
  }
