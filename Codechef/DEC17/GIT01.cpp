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

char x ;
int T, n, m, curr, ans=inf ;
char cake[101][101] ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> m ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=m ; j++)
            cin>> cake[i][j] ;
        ans=inf ; curr=0 ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=m ; j++)
            if(!((i+j)%2) && cake[i][j]!='R') curr+=3 ;
            else if((i+j)%2 && cake[i][j]!='G') curr+=5 ;
        ans=min(ans, curr) ;
        curr=0 ;
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=m ; j++)
            if(!((i+j)%2) && cake[i][j]!='G') curr+=5 ;
            else if((i+j)%2 && cake[i][j]!='R') curr+=3 ;
        ans=min(ans, curr) ;
        cout<< ans << endl ;
      }
  }
