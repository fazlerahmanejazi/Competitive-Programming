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
    string p, x ;
    bool pos=false, first=false, second=false ;
    cin>> p ;
    int n ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        if(x==p) pos=true ;
        if(x[1]==p[0]) first=true ;
        if(x[0]==p[1]) second=true ;
      }
    if(first && second) pos=true ;
    if(pos) cout<< "YES" ;
    else cout<< "NO" ;
  }
