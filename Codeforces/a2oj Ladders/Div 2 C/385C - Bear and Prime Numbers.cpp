#include <bits/stdc++.h>
using namespace std ;

int n, m, x ;
long long int l, r ;
vector<bool> isprime ;
vector<int> sum ;
vector<int> cnt(10000000+10, 0) ;

void sieve(int n)
  {
    sum.assign(n+10, 0) ;
    isprime.assign(n+10, true) ;
    isprime[0]=isprime[1]=false ;
    for(int i=2 ; i<=n ; i++)
      {
        if(isprime[i])
          for(int j=i ; j<=n ; j+=i)
            {
              isprime[j]=false ;
              sum[i]+=cnt[j] ;
            }
        sum[i]+=sum[i-1] ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        cnt[x]++ ;
      }
    cin>> m ;
    sieve(10000000) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> l >> r ;
        if(r>10000000) r=10000000 ;
        if(l>10000000) l=10000000 ;
        cout<< sum[r]-sum[l-1] << '\n' ;
      }
  }
