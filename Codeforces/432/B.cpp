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

bool collinear(lli x1, lli y1, lli x2, lli y2, lli x3, lli y3)
  {
    return (y1-y2)*(x1-x3)==(y1-y3)*(x1-x2) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli ax, ay, bx, by, cx, cy, distAB, distBC, distAC ;
    cin>> ax >> ay >> bx >> by >> cx >> cy ;
    distAB=(ax-bx)*(ax-bx)+(ay-by)*(ay-by) ;
    distBC=(cx-bx)*(cx-bx)+(cy-by)*(cy-by) ;
    if(distAB==distBC && !collinear(ax, ay, bx, by, cx, cy)) cout<< "Yes" ;
    else cout<< "No" ;
  }
