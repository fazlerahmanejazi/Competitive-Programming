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

#define pi acos(-1.0)
#define eps 1e-8

double max(int T, double x)
  {
    if(T==1) return 2*x ;
    else if(T==2) return sqrt(2)*x ;
    else return x ;
  }

double min(int T, double x)
  {
    if(T==1) return 2*x ;
    else if(T==2) return x ;
    else return (sqrt(3)*x)/2.0 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    double W, x ;
    int T, t, n, ans=0 ;
    cin>> T >> W >> n ;
    W=max(T, W) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> t >> x ;
        x=min(t, x) ;
        if(x<W+eps) ans++ ;
      }
    cout<< ans ;
  }
