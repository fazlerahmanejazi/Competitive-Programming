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

bool check(lli n)
  {
    if(n==0) false ;
      while(n>0)
        {
          if(!(n&1)) return false ;
          n=n>>1 ;
        }
    return true ;
  }

lli reverseBits(lli n)
  {
    int sz=log2(n)+1 ;
    bitset<64> a, x ;
    x=bitset<64>(n) ;
    for(int i=0 ; i<sz ; i++) a[i]=1-x[i] ;
    return a.to_ullong() ;
  }

pair<lli, lli> get(lli n)
  {
    int sz=log2(n)+1 ;
    bitset<64> a, b, x, s ;
    int p=0 ;
    x=bitset<64>(n) ;
    a.reset() ; b.reset() ;
    for(int i=0 ; i<sz ; i++)
      if(x[i]) a[i]=b[i]=1 ;
      else break ;
    for(int i=0 ; i<sz ; i++)
      if(!x[i])
        {
          a[i]=1-p ;
          b[i]=p ;
          p=1-p ;
        }
    lli A=a.to_ullong(), B=b.to_ullong() ;
    return mp(A, B) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        lli n, k, x ;
        cin>> n >> k ;
        if(k==1)
          {
            for(int i=1 ; i<=n ; i++) cout<< 1 << " " ;
            cout<< endl ;
          }
        else if(n==1) cout<< k << endl ;
        else if(n==2)
          {
            if(check(k)) cout<< k-1 << " " << 1 << endl ;
            else cout<< k << " " << reverseBits(k) << endl ;
          }
        else if(n==3)
          {
            if(check(k)) cout<< k << " " << 1  << " " << 1 << endl ;
            else cout<< k << " " << get(k).fi << " " << max(get(k).se, 1LL) << endl ;
          }
        else if(!(n%2))
          {
            if(check(k))
              {
                cout<< k-1 << " " << 1 << " " ;
                for(int i=3 ; i<=n ; i++) cout<< 1 << " " ;
                cout<< endl ;
              }
            else
              {
                cout<< k << " " << reverseBits(k) << " " ;
                for(int i=3 ; i<=n ; i++) cout<< 1 << " " ;
                cout<< endl ;
              }
          }
        else
          {
            if(check(k))
              {
                cout<< k << " " << 1  << " " << 1 << " " ;
                for(int i=4 ; i<=n ; i++) cout<< 1 << " " ;
                cout<< endl ;
              }
            else
              {
                cout<< k << " " << get(k).fi << " " << max(get(k).se, 1LL) << " " ;
                for(int i=4 ; i<=n ; i++) cout<< 1 << " " ;
                cout<< endl ;
              }
          }
      }
  }
