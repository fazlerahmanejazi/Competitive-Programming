#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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
    lli n, m, ans=0, curr, x, y, cnt ;
    cin>> n ;
    lli ingre[n+1] ;
    for(int i=0 ; i<n ; i++)
      cin>> ingre[i] ;
    cin>> m ;
    lli dish[m+1][n+1] ;
    for(int i=0 ; i<m ; i++)
      for(int j=0 ; j<n ; j++)
        cin>> dish[i][j] ;
    for(int i=0 ; i<m ; i++)
      for(int j=i+1 ; j<m ; j++)
        {
          curr=INF ;
          for(int k=0 ; k<n ; k++)
            {
              x=ingre[k] ;
              y=dish[i][k]+dish[j][k] ;
              if(y)
                {
                  cnt=x/y ;
                  curr=min(curr, x) ;
                }
            }
          ans=max(ans, curr) ;
        }
    cout<< ans ;
  }
