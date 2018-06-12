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
    string s, r, u="ABC" ;
    cin>> s ;
    for(int i=1 ; i<s.length()-1 ; i++)
      {
        r=s[i-1] ; r+=s[i] ; r+=s[i+1] ;
        sort(all(r)) ;
        if(r==u)
          {
            cout<< "Yes" ;
            return 0 ;
          }
      }
    cout<< "No" ;
  }
