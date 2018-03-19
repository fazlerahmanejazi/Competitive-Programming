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

int n, l, r, x, y, dp[110][110] ;
string s ;

void reconstruct(int l, int r)
  {
    if(l>r) return ;
    if(l==r)
      {
        if(s[l]=='(' || s[l]==')') cout<< "()" ;
        else cout<< "[]" ;
      }
    else if(r-l==1)
      {
        if(!dp[l][r])
          {
            if(s[l]=='(') cout<< "()" ;
            else cout<< "[]" ;
          }
        else reconstruct(l, l), reconstruct(r, r) ;
      }
    else
      {
        for(int i=l ; i<=r-1 ; i++)
          if(dp[l][i]+dp[i+1][r]==dp[l][r])
            {
              reconstruct(l, i) ;
              reconstruct(i+1, r) ;
              return ;
            }
        if((s[l]=='(' && s[r]==')') && dp[l+1][r-1]==dp[l][r])
          {
            cout<< '(' ;
            reconstruct(l+1, r-1) ;
            cout<< ')' ;
            return ;
          }
        if((s[l]=='[' && s[r]==']') && dp[l+1][r-1]==dp[l][r])
          {
            cout<< '[' ;
            reconstruct(l+1, r-1) ;
            cout<< ']' ;
            return ;
          }
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    n=s.length() ;
    s='#'+s ;
    memset(dp, inf, sizeof dp) ;
    for(int i=1 ; i<=n ; i++) dp[i][i]=1 ;
    for(int i=2 ; i<=n ; i++)
      for(int j=1 ; j+i-1<=n ; j++)
        {
          l=j ; r=j+i-1 ;
          for(int k=l ; k<=r-1 ; k++)
            {
              x=dp[l][k]+dp[k+1][r] ;
              if(x<dp[l][r]) dp[l][r]=x ;
            }
          if((s[l]=='(' && s[r]==')') || (s[l]=='[' && s[r]==']'))
            {
              if(i==2) x=0 ;
              else x=dp[l+1][r-1] ;
              if(x<dp[l][r]) dp[l][r]=x ;
            }
        }
    reconstruct(1, n) ;
  }
