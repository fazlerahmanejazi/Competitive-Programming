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
    int n, ax, ay, bx, by, cx, cy ;
    bool pos ;
    cin>> n >> ax >> ay >> bx >> by >> cx >> cy ;
    if(bx>cx) swap(bx, cx), swap(by, cy) ;
    pos=true ;
    for(int i=bx ; i<=cx ; i++) if(abs(i-ax)==abs(by-ay)) pos=false ;
    for(int i=by ; i<=cy ; i++) if(abs(i-ay)==abs(cx-ax)) pos=false ;
    if(pos) return cout<< "YES", 0 ;
    pos=true ;
    for(int i=by ; i<=cy ; i++) if(abs(i-ay)==abs(bx-ax)) pos=false ;
    for(int i=bx ; i<=cx ; i++) if(abs(i-ax)==abs(cy-ay)) pos=false ;
    if(pos) return cout<< "YES", 0 ;
    cout<< "NO" ;
  }
