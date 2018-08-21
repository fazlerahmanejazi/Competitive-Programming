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
    vlli a(4) ;
    lli ans=0, curr, m, M ;
    for(int i=0 ; i<4 ; i++)
      cin>> a[i] ;
    bool check=true ;
    while(check)
      {
        sort(all(a)) ;
        M=a[3] ; m=a[0] ;
        curr=M+2*m ;
        if(curr>ans) ans=curr ;
        if(a[0]==a[1]) check=false ;
        if(a[0]+1==a[1] && a[1]+1==a[2]) check=false ;
        tie(a[0], a[1], a[2], a[3])=mt(a[0]+2, a[1]-1, a[2]-1, a[3]-1) ;
        if(a[0]<0 || a[1]<0 || a[2]<0 || a[3]<0) check=false ;
      }
    cout<< ans ;
  }
