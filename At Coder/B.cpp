#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    long long int ans, l ;
    string s ;
    cin>> s ;
    l=s.length() ;
    ans=(l*(l-1)) ;
    for(int i=1 ; i<l-1 ; i++)
      if(s[i]=='U') ans+=i ;
      else ans+=l-1-i ;
    cout<< ans ;
  }
