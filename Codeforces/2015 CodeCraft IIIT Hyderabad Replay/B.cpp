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

bool checkPal(int h, int m, int s)
  {
    if(h/10!=s%10 || h%10!=s/10 || m/10!=m%10) return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int t[25][61][61], h1, h2, m1, m2, s1, s2, n, ans ;
    char c ;
    for(int h=0 ; h<24 ; h++)
      {
        if(h) t[h][0][0]+=t[h-1][59][59] ;
        for(int m=0 ; m<60 ; m++)
          {
            if(m) t[h][m][0]+=t[h][m-1][59] ;
            for(int s=0 ; s<60 ; s++)
              {
                if(s) t[h][m][s]+=t[h][m][s-1] ;
                if(checkPal(h, m, s)) t[h][m][s]++ ;
              }
          }
      }
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> h1 >> c >> m1 >> c >> s1 >> h2 >> c >> m2 >> c >> s2 ;
        ans=t[h2][m2][s2] ;
        if(s1) ans-=t[h1][m1][s1-1] ;
        else if(m1) ans-=t[h1][m1-1][59] ;
        else if(h1) ans-=t[h1-1][59][59] ;
        cout<< ans << endl ;
      }
  }
