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
    int cnt=0 ;
    string s, t, home, x ;
    int n ;
    cin>> n ;
    cin>> home ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        s=t="" ;
        s+=x[0] ; s+=x[1] ; s+=x[2] ;
        t+=x[5] ; t+=x[6] ; t+=x[7] ;
        if(s==home || t==home) cnt++ ;
      }
    if(cnt%2) cout<< "contest" ;
    else cout<< "home" ;
  }
