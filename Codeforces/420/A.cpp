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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    bool good=true ;
    cin>> n ;
    int lab[n][n] ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        cin>> lab[i][j] ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
        {
          int x=lab[i][j] ;
          if(x!=1)
            {
              bool check=false ;
              for(int k=0 ; k<n ; k++)
                if(k!=i)
                  {
                    int y=lab[k][j] ;
                    for(int l=0 ; l<n ; l++)
                      if(l!=j)
                        {
                          int z=lab[i][l] ;
                          if(x==z+y) check=true ;
                        }
                  }
              if(check==false) good=false ;
            }
        }
    if(good) cout<< "Yes" ;
    else cout<< "No" ;
  }
