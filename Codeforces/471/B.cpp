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
    string s ;
    cin>> s ;
    int cnt=0, pos=0 ;
    vector<int> check(26, 0), a ;
    for(int i=0 ; i<s.length() ; i++)
      {
        if(!check[s[i]-'a']) cnt++ ;
        check[s[i]-'a']++ ;
      }
    for(int i=0 ; i<26 ; i++) if(check[i]) a.push_back(check[i]) ;
    if(cnt==2)
      {
        if(a[0]>=2 && a[1]>=2) pos=1 ;
      }
    else if(cnt==3)
      {
        if(a[0]>=2 || a[1]>=2 || a[2]>=2) pos=1 ;
      }
    else if(cnt==4) pos=1 ;
    if(pos) cout<< "YES" ;
    else cout<< "NO" ;
  }
