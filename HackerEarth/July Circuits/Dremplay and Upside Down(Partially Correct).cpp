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
    int n, curr, ans ;
    string s ;
    cin>> s ;
    n=s.length() ;
    s='#'+s ;
    ans=inf ;
    for(int i=1 ; i<=n ; i++)
      {
        if(i>n/2)
          {
            curr=max(n-i, i-1) ;
            for(int j=1 ; j<=n, i-j>=1, i+j<=n ; j++)
              if(s[i+j]==s[i-j])
                curr-- ;
            ans=min(curr, ans) ;
          }
        if(i>=(n+1)/2)
          {
            curr=i ;
            for(int j=1 ; j<=n, i-j+1>=1, i+j<=n ; j++)
              if(s[i+j]==s[i-j+1])
                curr-- ;
            ans=min(curr, ans) ;
          }
      }
    cout<< ans ;
  }
