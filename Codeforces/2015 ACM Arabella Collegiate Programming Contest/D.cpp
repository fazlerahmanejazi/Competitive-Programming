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
    int T ;
    cin>> T ;
    while(T--)
      {
        bool pos=true ;
        char grid[10][10] ;
        for(int i=1 ; i<=9 ; i++)
          for(int j=1 ; j<=9 ; j++)
            cin>> grid[i][j] ;
        for(int i=1 ; i<=9 ; i+=3)
          for(int j=1 ; j<=9 ; j+=3)
            {
              bool check=true ;
              vi taken(10, 0) ;
              for(int k=i ; k<i+3 ; k++)
                for(int l=j ; l<j+3 ; l++)
                  taken[grid[k][l]-'0']=1 ;
              for(int k=1 ; k<=9 ; k++) if(!taken[k]) check=false ;
              if(!check) pos=false ;
            }
        for(int i=1 ; i<=9 ; i++)
          {
            bool check=true ;
            vi taken(10, 0) ;
            for(int j=1 ; j<=9 ; j++) taken[grid[i][j]-'0']=1 ;
            for(int j=1 ; j<=9 ; j++) if(!taken[j]) check=false ;
            if(!check) pos=false ;
          }
        for(int i=1 ; i<=9 ; i++)
          {
            bool check=true ;
            vi taken(10, 0) ;
            for(int j=1 ; j<=9 ; j++) taken[grid[j][i]-'0']=1 ;
            for(int j=1 ; j<=9 ; j++) if(!taken[j]) check=false ;
            if(!check) pos=false ;
          }
        if(pos) cout<< "Valid" << endl ;
        else cout<< "Invalid" << endl ;
      }
  }
