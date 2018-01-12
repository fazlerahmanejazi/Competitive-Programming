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

int T, n, l, r ;
lli ans ;
vb good(1001, true), isprime(1001, true) ;
vi prime, a, cnt(1001, 0) ;
bool check ;

void seive()
  {
    isprime[1]=false ;
    for(int i=2 ; i*i<=1000 ; i++)
      if(isprime[i])
        for(int j=i*i ; j<=1000 ; j+=i)
          isprime[j]=false ;
    for(int i=2 ; i<=1000 ; i++)
      if(isprime[i])
        prime.pb(i) ;
  }

void preprocess()
  {
    for(int i=1 ; i<=1000 ; i++)
      {
        int n=i ;
        for(int j=0 ; j<prime.size(), prime[j]<=sqrt(n) ; j++)
          {
            int cnt=0 ;
            while(n%prime[j]==0)
              {
                cnt++ ;
                n/=prime[j] ;
              }
            if(cnt>1)
              {
                good[i]=false ;
                break ;
              }
          }
      }
  }

void add(int n)
  {
    for(int j=0 ; j<prime.size(), prime[j]<=sqrt(n) ; j++)
      while(n%prime[j]==0)
        {
          cnt[prime[j]]++ ;
          n/=prime[j] ;
        }
    cnt[n]++ ;
  }

void del(int n)
  {
    for(int j=0 ; j<prime.size(), prime[j]<=sqrt(n) ; j++)
      {
        while(n%prime[j]==0)
          {
            cnt[prime[j]]-- ;
            n/=prime[j] ;
          }
        if(cnt[prime[j]]<0) cnt[prime[j]]=0 ;
      }
    cnt[n]-- ;
    if(cnt[n]<0) cnt[n]=0 ;
  }

lli ways(lli x)
  {
    return x*(x+1)/2 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    seive() ;
    preprocess() ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        a.clear() ; a.resize(n) ;
        cnt.assign(1001, 0) ;
        for(int i=0 ; i<n ; i++)
          cin>> a[i] ;
        ans=l=r=0 ;
        check=false ;
        while(l<n)
          {
            if(check)
              {
                ans+=ways(r-l) ;
                if(r==n) break ;
                bool repeat=true ;
                while(l<n && repeat)
                  {
                    del(a[l]) ;
                    l++ ;
                    repeat=false ;
                    for(int i=0 ; i<prime.size(), prime[i]<=a[l] ; i++)
                      if(cnt[prime[i]]>1)
                        {
                          repeat=true ;
                          break ;
                        }
                  }
                if(good[a[r]]) ans-=ways(r-l) ;
                check=false ;
              }
            else
              {
                if(!good[a[r]])
                  {
                    while(r<n && !good[a[r]]) r++ ;
                    l=r ;
                    cnt.assign(1001, 0) ;
                    if(r==n) break ;
                  }
                if(r<n) del(a[r]) ;
                while(r<n)
                  {
                    add(a[r]) ;
                    for(int i=0 ; i<prime.size(), prime[i]<=a[r] ; i++)
                      if(cnt[prime[i]]>1)
                        {
                          check=true ;
                          break ;
                        }
                    if(check) break ;
                    r++ ;
                  }
                if(r==n) check=true ;
              }
          }
        cout<< ans << endl ;
      }
  }
