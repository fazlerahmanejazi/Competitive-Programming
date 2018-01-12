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

bool collinear(int x1, int y1, int x2, int y2, int x3, int y3)
  {
    return (y1-y2)*(x1-x3)==(y1-y3)*(x1-x2) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, ans=0, curr ;
    cin>> n ;
    vpii point(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> point[i].fi >> point[i].se ;
    for(int i=0 ; i<n ; i++)
      for(int j=i+1 ; j<n ; j++)
        {
          curr=2 ;
          for(int k=j+1 ; k<n ; k++)
            if(collinear(point[i].fi, point[i].se, point[j].fi, point[j].se, point[k].fi, point[k].se))
              curr++ ;
          ans=max(curr, ans) ;
        }
    cout<< ans ;
  }
