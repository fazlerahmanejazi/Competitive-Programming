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
using pii = pair<lli, lli> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<lli, lli>> ;

int A, B, C ;

int region(long double x, long double y)
  {
    if(x<C) return 1 ;
    else if(x<=C+A)
      {
        if(y<=B) return 2 ;
        else if(y<=B+C) return 3 ;
        else if(y<=2*B+C) return 4 ;
        else return 5 ;
      }
    else return 6 ;
  }

void transform(long double &x, long double &y, long double &z)
  {
    int r=region(x, y) ;
    if(r==1) z=C-x, x=C ;
    else if(r==2) y=2*B+C-y, z=C ;
    else if(r==3) z=B+C-y, y=B+C ;
    else if(r==4) ;
    else if(r==5) z=y-2*B-C, y=2*B+C ;
    else z=x-A-C, x=A+C ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    long double x1, x2, y1, y2, z1=0, z2=0, ans ;
    cin>> A >> B >> C >> x1 >> y1 >> x2 >> y2 ;
    transform(x1, y1, z1) ;
    transform(x2, y2, z2) ;
    ans=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)) ;
    cout<< fixed << setprecision(9) << ans ;
  }
