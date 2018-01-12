#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod (lli)1000000007
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

lli t, l, r, c, d, ans ;
vb isprime ;
vlli prime, X, F ;
bool check ;

void seive()
  {
    isprime.assign(3000+1, true) ;
    for(int i=2 ; i*i<=3000 ; i++)
      if(isprime[i])
        for(int j=i*i ; j<=3000 ; j+=i)
          isprime[j]=false ;
    prime.pb(2) ;
    for(int i=3 ; i<=3000 ; i+=2)
      if(isprime[i])
        prime.pb(i) ;
  }

void generate()
  {
    X.resize(r+1) ;
    F.assign(r+1, 0) ;
    for(int i=1 ; i<=r ; i++)
      {
        lli c=i ;
        for(int j=0 ; prime[j]*prime[j]<=c ; j++)
          if(c%prime[j]==0)
            {
              X[c]=prime[j] ;
              c=-1 ;
              break ;
            }
        if(c!=-1) X[c]=c ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> t >> l >> r ;
    seive() ;
    generate() ;
    ans=d=0 ;
    for(int i=1 ; i<=r ; i++)
      {
        c=i/X[i] ;
        F[i]=(F[c]+(c*((X[i]-1)*X[i]/2)%mod)%mod)%mod ;
      }
    for(int i=r ; i>=l ; i--)
      {
        ans*=t ;
        ans%=mod ;
        ans+=F[i] ;
        ans%=mod ;
      }
    cout << ans ;
  }
