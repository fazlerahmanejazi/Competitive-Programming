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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, k, m, x, a, b, U, c=0 ;
    cin>> n >> k >> m ;
    x=log2(k) ;
    U=pow(2, n) ;
    vi A(U+10, 0), play ;
    a=k ;
    b=k+1 ;
    for(int i=1 ; i<=U ; i++)
      if(i!=a && i!=b)
        play.pb(i) ;
    if(a==U && x==m)
      {
        for(int i=1 ; i<=U ; i++)
          cout<< i << " " ;
      }
    else if(m>x || b>U) cout<< -1 ;
    else
      {
        A[1]=a ;
        A[pow(2, m+1)]=b ;
        for(int i=1 ; i<=U ; i++)
          if(!A[i])
            A[i]=play[c++] ;
        for(int i=1 ; i<=U ; i++)
          cout<< A[i] << " " ;
      }
  }
