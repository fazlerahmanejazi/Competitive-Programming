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

lli get(string &a, string &b)
  {
    lli cnt=0, ans=0 ;
    string x="" ;
    x=a+b ;
    for(int i=0 ; i<x.length() ; i++)
      if(x[i]=='s') cnt++ ;
      else ans+=cnt ;
    return ans ;
  }

bool cmp(string a, string b)
  {
    return get(b, a)<get(a, b) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, cnt=0, ans=0 ;
    cin>> n ;
    vector<string> s(n) ;
    for(int i=0 ; i<n ; i++) cin>> s[i] ;
    sort(all(s), cmp) ;
    string x="" ;
    for(int i=0 ; i<n ; i++) x+=s[i] ;
    for(int i=0 ; i<x.length() ; i++)
      if(x[i]=='s') cnt++ ;
      else ans+=cnt ;
    cout<< ans ;
  }
