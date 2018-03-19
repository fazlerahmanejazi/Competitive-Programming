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
    int n, q, m, ans, other, dp[30][1510] ;
    string s;
    char fav ;
    cin>> n >> s >> q ;
    memset(dp, 0, sizeof dp) ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> m >> fav ;
        if(dp[fav-'a'][m]) cout<< dp[fav-'a'][m] << endl ;
        else
          {
            int l=0, r=0 ;
            other=ans=0 ;
            if(s[l]!=fav) other++ ;
            while(l<n)
              {
                if(other<=m)
                  {
                    ans=max(ans, r-l+1) ;
                    if(r+1<n)
                      {
                        r++ ;
                        if(s[r]!=fav) other++ ;
                      }
                    else
                      {
                        if(s[l]!=fav) other-- ;
                        l++ ;
                      }
                  }
                else
                  {
                    if(s[l]!=fav) other-- ;
                    l++ ;
                  }
              }
            dp[fav-'a'][m]=ans ;
            cout<< ans << endl ;
          }
      }
  }
