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

lli n, T, x, mx, ans, curr, cnt[1000010] ;
vlli sumPrime(1000010, 0) ;

void seive()
  {
    for(int i=2 ; i<=1000000 ; i++)
      if(!sumPrime[i])
        for(int j=i ; j<=1000000 ; j+=i)
          sumPrime[j]+=i ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    seive() ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        memset(cnt, 0, sizeof cnt) ;
        ans=mx=0 ;
        for(int i=0 ; i<n ; i++) cin>> x, cnt[x]++, mx=max(mx, x) ;
        for(int i=2 ; i<=mx ; i++)
          if(cnt[i])
            {
              curr=0 ;
              for(int j=2*i ; j<=mx ; j+=i)
                if(cnt[j] && !(sumPrime[j]%sumPrime[i]))
                  curr+=cnt[j] ;
              ans+=curr*cnt[i] ;
              ans+=cnt[i]*(cnt[i]-1) ;
            }
        cout<< ans << endl ;
      }
  }
