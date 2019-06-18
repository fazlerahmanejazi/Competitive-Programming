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

const lli MAX=(1ll<<32)-1 ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli l, x=0, n ;
    stack<pair<lli, lli>> st ;
    string s ;
    cin>> l ;
    while(l--)
      {
        cin>> s ;
        if(s=="add")
          {
            x++ ;
            if(x>MAX) return cout<< "OVERFLOW!!!", 0 ;
          }
        else if(s=="for")
          {
            cin>> n ;
            st.push(mp(x, n)) ;
          }
        else
          {
            x+=(x-st.top().fi)*(st.top().se-1) ;
            st.pop() ;
            if(x>MAX) return cout<< "OVERFLOW!!!", 0 ;
          }
      }
    cout<< x ;
  }
