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

int n, m, k ;
char S[305][305] ;

bool check(int x, int y, int r)
  {
    if(x-r<1 || y-r<1 || x+r>n || y+r>m) return false ;
    if(S[x][y]=='*' && S[x-r][y]=='*' && S[x][y-r]=='*' && S[x][y+r]=='*' && S[x+r][y]=='*') return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m >> k ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        cin>> S[i][j] ;
    for(int r=1 ; r<=min(n, m) ; r++)
      for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++)
            if(check(i, j, r))
              {
                if(k>1) k-- ;
                else
                  {
                    cout<< i << " " << j << endl ;
                    cout<< i-r << " " << j << endl << i+r << " " << j << endl ;
                    cout<< i << " " << j-r << endl << i << " " << j+r << endl ;
                    return 0 ;
                  }
              }
    cout<< -1 ;
  }
